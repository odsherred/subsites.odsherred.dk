<?php

/**
 * Implements hook_panels_layouts().
 */
$plugin = array(
  'title' => t('OS2Web Col 2 - 1-3'),
  'category' => t('CMS Theme'),
  'icon' => 'os2web_2col-1-3.png',
  'theme' => 'panels_os2web_2col-1-3',
  'theme arguments' => array('id', 'content'),
  'admin css' => 'os2web_2col-1-3_admin.css',
  'regions' => array(
    'col1' => t('Left'),
    'col2' => t('Right')
  ),
);
