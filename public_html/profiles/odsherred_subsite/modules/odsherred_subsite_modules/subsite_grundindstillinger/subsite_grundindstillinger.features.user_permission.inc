<?php

/**
 * @file
 * subsite_grundindstillinger.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function subsite_grundindstillinger_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access site map'.
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(),
    'module' => 'linkit',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'let bruger' => 'let bruger',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'super bruger' => 'super bruger',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format kun_tekst'.
  $permissions['use text format kun_tekst'] = array(
    'name' => 'use text format kun_tekst',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
