#!/bin/bash

# This file should get the files from the site creator and create the
# neccesarry configurations for the subsite.

BASE_DIR="/var/www/subsites.odsherred.dk/subsites-creator"

QUEUE_DIR="${BASE_DIR}/queue"
COMPLETE_DIR="${BASE_DIR}/complete"
PROCESSING_DIR="${BASE_DIR}/processing"
FAILED_DIR="${BASE_DIR}/failed"

RUNNINGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
MULTISITE="/var/www/subsites.odsherred.dk/public_html"
TMPDIRBASE="/var/www/subsites.odsherred.dk/tmp"
DBDIR="/var/lib/mysql"
VHOST="/etc/apache2/sites-available/subsites.odsherred.dk"
SITESFILE="$MULTISITE/sites/sites.php"
SERVERIP="192.168.2.227"

function addVhostAlias () {
  if [ -z "$1" ]
  then
    echo "FAILED. Empty or no name passed to addVhostAlias"
    exit
  fi
  /usr/bin/perl -p -i -e "s/ServerName subsites.odsherred.dk/ServerName subsites.odsherred.dk\n    ServerAlias $1/g" $VHOST
}

if [ ! `ls $QUEUE_DIR` ]; then
  exit
fi

for i in `ls $QUEUE_DIR/*`; do
  source $i
  SITENAMETRIMMED=`echo $SITENAME | tr -d ' '`
  TMPDIR="$TMPDIRBASE/$SITENAMETRIMMED"
  DBNAME=`echo $SITENAMETRIMMED |  sed 's/\./_/g'`
  DBUSER=`echo $DBNAME | cut -c 1-16`
  DBPASS=`pwgen -s 10 1`
#  ADMINPASS=`pwgen -s 10 1`
  NOW=`date +"%d/%m/%y %H:%M:%S"`

  # Check if site dir already exists
  if [ -d $MULTISITE/sites/$SITENAMETRIMMED ]
  then
    echo "FAILED - sitedir, $SITENAMETRIMMED exists ($i)"
    mv $i $FAILED_DIR
    exit
  fi

  # Check if site vhost alias already exists
  ALIASEXIST=`egrep -c "ServerAlias $SITENAME\$" $VHOST`
  if [ $ALIASEXIST -ne 0 ]
  then
    echo "FAILED - site exist in vhost already ($i)"
    mv $i $FAILED_DIR
    exit
  fi

  # Check if database already exists
  if [ -d $DBDIR/$DBNAME ]
  then
    echo "FAILED - db exists ($i)"
    mv $i $FAILED_DIR
    exit
  fi

# move to processing dir to avoid multiple runs
  mv $i $PROCESSING_DIR

# Create database and database user
  /usr/bin/mysql -u root -e "CREATE DATABASE $DBNAME;"
  /usr/bin/mysql -u root -e "GRANT ALL ON $DBNAME.* TO $DBUSER@localhost IDENTIFIED BY \"$DBPASS\"";

# Add to vhost
  addVhostAlias $SITENAME

# add to hostsfile
  echo "$SERVERIP    $SITENAMETRIMMED" >> /etc/hosts

# only loop alt names if there are any..
  for ALTNAME in "${ALTNAMES[@]}"
  do
    # Check if site vhost alias already exists
    ALIASEXIST=`egrep -c "ServerAlias $ALTNAME\$" $VHOST`
    if [ $ALIASEXIST -ne 0 ]
    then
      echo "FAILED - site alt name exist in vhost already ($i). Skipping"
      continue
    fi
    addVhostAlias $ALTNAME
    # Add to sites.php
    echo "\$sites['$ALTNAME'] = '$SITENAME';" >> $SITESFILE# add to hostsfile
  echo "$SERVERIP    $ALTNAME" >> /etc/hosts
  done

# reload apache
  /etc/init.d/apache2 reload &> /dev/null

# Create tmpdir
  mkdir $TMPDIR

# Do a drush site install
  /usr/bin/drush -q -y -r $MULTISITE site-install $PROFILE --db-url="mysql://$DBUSER:$DBPASS@localhost/$DBNAME" --sites-subdir=$SITENAMETRIMMED --account-mail=$EMAIL --site-mail=$EMAIL --site-name=$SITENAMETRIMMED --account-pass=$ADMINPASS

# Set tmp
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED vset file_temporary_path $TMPDIR

# Do some drupal setup here. Don't trust the profile :)
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED dis update comment
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED vset user_register 0

  # Enforce features
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED fr -y --force subsite_grundindstillinger
  # Enable reservation calender
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED en od_music_agreservation

# Enable and update translations. This is disabled during install.
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED en l10n_update
#  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED langadd da
#  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED language-default da
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED l10n-update-refresh
  /usr/bin/drush -q -y -r $MULTISITE --uri=$SITENAMETRIMMED l10n-update

# add to crontab
  CRONKEY=`/usr/bin/drush -r $MULTISITE --uri=$SITENAMETRIMMED vget cron_key | cut -d \" -f 2`
  CRONLINE="30 * * * * wget -O - -q -t 1 http://$SITENAMETRIMMED/cron.php?cron_key=$CRONKEY"
  (/usr/bin/crontab -u www-data -l; echo "$CRONLINE") | /usr/bin/crontab -u www-data -

# Set correct permissions
  /bin/chgrp -R www-data $MULTISITE/sites/$SITENAMETRIMMED $TMPDIR
  /bin/chmod -R g+rwX $MULTISITE/sites/$SITENAMETRIMMED $TMPDIR
  /bin/chmod g-w $MULTISITE/sites/$SITENAMETRIMMED $MULTISITE/sites/$SITENAMETRIMMED/settings.php

# Move file to completed
  PROCESSING_FILE=$(basename $i)
  mv $PROCESSING_DIR/$PROCESSING_FILE $COMPLETE_DIR

# add admin info to the file in completed
  echo "Subsite created $NOW" >> $COMPLETE_DIR/`basename $i`
  echo "http://$SITENAMETRIMMED - admin / $ADMINPASS" >> $COMPLETE_DIR/`basename $i`

# send mail about the new site
  echo "Subsite created $NOW"
  echo "http://$SITENAMETRIMMED - admin / $ADMINPASS"

done
