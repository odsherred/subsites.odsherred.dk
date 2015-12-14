<?php

/**
 * Implements hook_panels_layouts().
 */
$plugin = array(
  'title' => t('OS2Web Forside'),
  'category' => t('CMS Theme'),
  'icon' => 'os2web_forside.png',
  'theme' => 'panels_os2web_forside',
  'theme arguments' => array('id', 'content'),
  'admin css' => 'os2web_forside_admin.css',
  'regions' => array(
    'top_left' => t('Top left'),
    'top_right' => t('Top right'),
    'bottom' => t('Bottom'),
  ),
);
