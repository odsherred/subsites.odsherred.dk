<?php

/**
 * Implements hook_panels_layouts().
 */
$plugin = array(
  'title' => t('OS2Web Forside 5-7'),
  'category' => t('CMS Theme'),
  'icon' => 'os2web_forside-4-8.png',
  'theme' => 'panels_os2web_forside-5-7',
  'theme arguments' => array('id', 'content'),
  'admin css' => 'os2web_forside-4-8_admin.css',
  'regions' => array(
    'top_left' => t('Top left'),
    'top_right' => t('Top right'),
    'bottom' => t('Bottom'),
  ),
);
