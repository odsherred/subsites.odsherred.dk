<?php

/**
 * Implements hook_panels_layouts().
 */
$plugin = array(
  'title' => t('OS2Web 4 Kol'),
  'category' => t('CMS Theme'),
  'icon' => 'os2web_4kol.png',
  'theme' => 'panels_os2web_4kol',
  'theme arguments' => array('id', 'content'),
  'admin css' => 'os2web_4kol_admin.css',
  'regions' => array(
    'kol1' => t('Kol 1'),
    'kol2' => t('Kol 2'),
    'kol3' => t('Kol 3'),
    'kol4' => t('Kol 4'),
  ),
);
