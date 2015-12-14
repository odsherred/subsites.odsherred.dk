<?php

/**
 * Implements hook_panels_layouts().
 */
$plugin = array(
  'title' => t('OS2Web Portal'),
  'category' => t('CMS Theme'),
  'icon' => 'os2web_portal.png',
  'theme' => 'panels_os2web_portal',
  'theme arguments' => array('id', 'content'),
  'admin css' => 'os2web_portal_admin.css',
  'regions' => array(
    'lead' => t('Lead'),
    'middle_top' => t('Middle top'),
    'middle_center' => t('Middle center'),
    'middle_right' => t('Middle right'),
  ),
);
