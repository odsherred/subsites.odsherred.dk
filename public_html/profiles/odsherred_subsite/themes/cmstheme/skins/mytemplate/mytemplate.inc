<?php
function cmstheme_skinr_skin_mytemplate_info() {

  $skins = array();

  $skins['mytemplate_bgcolor'] = array(
    'title' => t('Background color'),
    'description' => t('None'),
    'type' => 'select',
    'default status' => TRUE,
    'options' => array(
      'color_1' => array('title' => t('Green medium'), 'class' => array('medium-green-bg')),
      'color_2' => array('title' => t('Green light'), 'class' => array('light-green-bg')),
      'color_3' => array('title' => t('Blue dark'), 'class' => array('dark-blue-bg')),
      'color_4' => array('title' => t('Blue dark opaque'), 'class' => array('dark-blue-opaque-bg')),
      'color_5' => array('title' => t('Blue medium'), 'class' => array('medium-blue-bg')),
      'color_6' => array('title' => t('Gray dark'), 'class' => array('dark-gray-bg')),
    ),
  );
  $skins['mytemplate_rounded_corners'] = array(
    'title' => t('Rounded corners'),
    'description' => t('None'),
    'type' => 'select',
    'default status' => TRUE,
    'options' => array(
      'rounded_1' => array('title' => t('Slightly rounded'), 'class' => array('slightly-rounded-corners')),
      'rounded_2' => array('title' => t('Well rounded'), 'class' => array('well-rounded-corners')),
    ),
  );
  $skins['mytemplate_inline_menus'] = array(
    'title' => t('Format ul.menu as inline menu'),
    'description' => t('None'),
    'type' => 'checkboxes',
    'default status' => TRUE,
    'options' => array(
      'inline' => array('title' => t('Enable inline menu'), 'class' => array('inline-menu')),
    ),
  );
  $skins['mytemplate_link-color'] = array(
    'title' => t('Change color of links'),
    'description' => t('None'),
    'type' => 'select',
    'default status' => TRUE,
    'options' => array(
      'link-color1' => array('title' => t('White links'), 'class' => array('white-links')),
      'link-color2' => array('title' => t('Dark gray links'), 'class' => array('dark-gray-links')),
    ),
  );
  return $skins;
}
