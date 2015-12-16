<?php
/**
 * @file
 * subsite_event_calendar.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function subsite_event_calendar_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create od_event content'.
  $permissions['create od_event content'] = array(
    'name' => 'create od_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any od_event content'.
  $permissions['delete any od_event content'] = array(
    'name' => 'delete any od_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own od_event content'.
  $permissions['delete own od_event content'] = array(
    'name' => 'delete own od_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any od_event content'.
  $permissions['edit any od_event content'] = array(
    'name' => 'edit any od_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own od_event content'.
  $permissions['edit own od_event content'] = array(
    'name' => 'edit own od_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  return $permissions;
}
