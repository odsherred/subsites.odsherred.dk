<?php

/**
 * @file
 * subsite_grundindstillinger.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function subsite_grundindstillinger_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function subsite_grundindstillinger_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function subsite_grundindstillinger_image_default_styles() {
  $styles = array();

  // Exported image style: banner.
  $styles['banner'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 930,
          'height' => 280,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'banner',
  );

  // Exported image style: indholdsside.
  $styles['indholdsside'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 690,
          'height' => 235,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'indholdsside',
  );

  // Exported image style: indholdsside_alt.
  $styles['indholdsside_alt'] = array(
    'label' => 'indholdsside_alt',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 340,
          'height' => 235,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: lille_nyhed.
  $styles['lille_nyhed'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 130,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'lille_nyhed',
  );

  // Exported image style: subsite_side.
  $styles['subsite_side'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 680,
          'height' => 265,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'subsite_side',
  );

  // Exported image style: velkomst.
  $styles['velkomst'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 440,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'velkomst',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function subsite_grundindstillinger_node_info() {
  $items = array(
    'banner' => array(
      'name' => t('Banner'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Simpel side'),
      'base' => 'node_content',
      'description' => t('Brug <em>simple sider</em> til dit statiske indhold, som f.eks. en "om os"-side.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'subsite_nyhed' => array(
      'name' => t('Subsite nyhed'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'help' => '',
    ),
    'velkomst' => array(
      'name' => t('Velkomst'),
      'base' => 'node_content',
      'description' => t('Bruges til at lave nye velkomsthilsener på forsiden. Det vil altid være den nyeste, der er publiceret, der vises.'),
      'has_title' => '1',
      'title_label' => t('Velkomst overskrift'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
