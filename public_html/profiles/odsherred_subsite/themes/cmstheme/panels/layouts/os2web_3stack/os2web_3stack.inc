<?php

/**
 * Implements hook_panels_layouts().
 */
$plugin = array(
  'title' => t('OS2Web 3 Stack'),
  'category' => t('CMS Theme'),
  'icon' => 'os2web_3stack.png',
  'theme' => 'panels_os2web_3stack',
  'theme arguments' => array('id', 'content'),
  'admin css' => 'os2web_3stack_admin.css',
  'regions' => array(
    'stack1' => t('Top'),
    'stack2' => t('Midt'),
    'stack3' => t('Bund'),
  ),
);
