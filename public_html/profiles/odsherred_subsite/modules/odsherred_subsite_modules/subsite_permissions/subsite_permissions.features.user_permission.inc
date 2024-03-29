<?php

/**
 * @file
 * subsite_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function subsite_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'let bruger' => 'let bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'user',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create banner content'.
  $permissions['create banner content'] = array(
    'name' => 'create banner content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create kontaktinfo content'.
  $permissions['create kontaktinfo content'] = array(
    'name' => 'create kontaktinfo content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create selv content'.
  $permissions['create selv content'] = array(
    'name' => 'create selv content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create spotboks content'.
  $permissions['create spotboks content'] = array(
    'name' => 'create spotboks content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create subsite_nyhed content'.
  $permissions['create subsite_nyhed content'] = array(
    'name' => 'create subsite_nyhed content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create velkomst content'.
  $permissions['create velkomst content'] = array(
    'name' => 'create velkomst content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any banner content'.
  $permissions['delete any banner content'] = array(
    'name' => 'delete any banner content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any kontaktinfo content'.
  $permissions['delete any kontaktinfo content'] = array(
    'name' => 'delete any kontaktinfo content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any selv content'.
  $permissions['delete any selv content'] = array(
    'name' => 'delete any selv content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any spotboks content'.
  $permissions['delete any spotboks content'] = array(
    'name' => 'delete any spotboks content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any subsite_nyhed content'.
  $permissions['delete any subsite_nyhed content'] = array(
    'name' => 'delete any subsite_nyhed content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any velkomst content'.
  $permissions['delete any velkomst content'] = array(
    'name' => 'delete any velkomst content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own banner content'.
  $permissions['delete own banner content'] = array(
    'name' => 'delete own banner content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own kontaktinfo content'.
  $permissions['delete own kontaktinfo content'] = array(
    'name' => 'delete own kontaktinfo content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own selv content'.
  $permissions['delete own selv content'] = array(
    'name' => 'delete own selv content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own spotboks content'.
  $permissions['delete own spotboks content'] = array(
    'name' => 'delete own spotboks content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own subsite_nyhed content'.
  $permissions['delete own subsite_nyhed content'] = array(
    'name' => 'delete own subsite_nyhed content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own velkomst content'.
  $permissions['delete own velkomst content'] = array(
    'name' => 'delete own velkomst content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any banner content'.
  $permissions['edit any banner content'] = array(
    'name' => 'edit any banner content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any kontaktinfo content'.
  $permissions['edit any kontaktinfo content'] = array(
    'name' => 'edit any kontaktinfo content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any selv content'.
  $permissions['edit any selv content'] = array(
    'name' => 'edit any selv content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any spotboks content'.
  $permissions['edit any spotboks content'] = array(
    'name' => 'edit any spotboks content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any subsite_nyhed content'.
  $permissions['edit any subsite_nyhed content'] = array(
    'name' => 'edit any subsite_nyhed content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any velkomst content'.
  $permissions['edit any velkomst content'] = array(
    'name' => 'edit any velkomst content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own banner content'.
  $permissions['edit own banner content'] = array(
    'name' => 'edit own banner content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own kontaktinfo content'.
  $permissions['edit own kontaktinfo content'] = array(
    'name' => 'edit own kontaktinfo content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own selv content'.
  $permissions['edit own selv content'] = array(
    'name' => 'edit own selv content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own spotboks content'.
  $permissions['edit own spotboks content'] = array(
    'name' => 'edit own spotboks content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own subsite_nyhed content'.
  $permissions['edit own subsite_nyhed content'] = array(
    'name' => 'edit own subsite_nyhed content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own velkomst content'.
  $permissions['edit own velkomst content'] = array(
    'name' => 'edit own velkomst content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'administrator' => 'administrator',
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'media_bulk_upload',
  );

  // Exported permission: 'publish any content'.
  $permissions['publish any content'] = array(
    'name' => 'publish any content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish any page content'.
  $permissions['publish any page content'] = array(
    'name' => 'publish any page content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish any spotboks content'.
  $permissions['publish any spotboks content'] = array(
    'name' => 'publish any spotboks content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable content'.
  $permissions['publish editable content'] = array(
    'name' => 'publish editable content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable page content'.
  $permissions['publish editable page content'] = array(
    'name' => 'publish editable page content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable spotboks content'.
  $permissions['publish editable spotboks content'] = array(
    'name' => 'publish editable spotboks content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own page content'.
  $permissions['publish own page content'] = array(
    'name' => 'publish own page content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own spotboks content'.
  $permissions['publish own spotboks content'] = array(
    'name' => 'publish own spotboks content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'unpublish any content'.
  $permissions['unpublish any content'] = array(
    'name' => 'unpublish any content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any page content'.
  $permissions['unpublish any page content'] = array(
    'name' => 'unpublish any page content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any spotboks content'.
  $permissions['unpublish any spotboks content'] = array(
    'name' => 'unpublish any spotboks content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable content'.
  $permissions['unpublish editable content'] = array(
    'name' => 'unpublish editable content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable page content'.
  $permissions['unpublish editable page content'] = array(
    'name' => 'unpublish editable page content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable spotboks content'.
  $permissions['unpublish editable spotboks content'] = array(
    'name' => 'unpublish editable spotboks content',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own page content'.
  $permissions['unpublish own page content'] = array(
    'name' => 'unpublish own page content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own spotboks content'.
  $permissions['unpublish own spotboks content'] = array(
    'name' => 'unpublish own spotboks content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'search',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'super bruger' => 'super bruger',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'let bruger' => 'let bruger',
      'super bruger' => 'super bruger',
    ),
    'module' => 'node',
  );

  return $permissions;
}
