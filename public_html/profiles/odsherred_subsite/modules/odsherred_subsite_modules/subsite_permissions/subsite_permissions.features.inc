<?php

/**
 * @file
 * subsite_permissions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function subsite_permissions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
