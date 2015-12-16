<?php
/**
 * @file
 * subsite_grundindstillinger.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function subsite_grundindstillinger_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_ls-hjt:http://www.adgangforalle.dk/
  $menu_links['user-menu_ls-hjt:http://www.adgangforalle.dk/'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'http://www.adgangforalle.dk/',
    'router_path' => '',
    'link_title' => 'Læs højt',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_ls-hjt:http://www.adgangforalle.dk/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: user-menu_sitemap:sitemap
  $menu_links['user-menu_sitemap:sitemap'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Sitemap',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_sitemap:sitemap',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Læs højt');
  t('Sitemap');


  return $menu_links;
}
