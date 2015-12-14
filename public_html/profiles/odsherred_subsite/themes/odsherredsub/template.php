<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * implements hook_preprocess_page()
 *
 **/
function odsherredsub_preprocess_html(&$variables) { 
  drupal_add_css(path_to_theme() . '/css/font-awesome/css/font-awesome.min.css');
  //$file = theme_get_setting('theme_color') . '-style.css';
  //drupal_add_css(path_to_theme() . '/css/'. $file, array('group' => CSS_THEME, 'weight' => 115,'browsers' => array(), 'preprocess' => FALSE));
}

/**
 * Implements template_process_page().
 */
function odsherredsub_process_page(&$variables, $hook) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
}


function odsherredsub_preprocess_page(&$variables, $hook) {
  // Add the site structure term id to the page div
  $node = node_load(arg(1));

  if(is_object($node) && isset($node->field_site_structure))
  {
    $termParents = taxonomy_get_parents($node->field_site_structure[LANGUAGE_NONE][0]['tid']);
    $termId = 'tid-'.$node->field_site_structure[LANGUAGE_NONE][0]['tid'];
    $termIdParent = "";
    if(!empty($termParents))
    {
      $termIdParent = 'tid-'.key($termParents);  
    }

    $variables['attributes_array']['class'] = $termIdParent . ' ' . $termId;
  }
}

function odsherredsub_image_style($variables) {
  // Determine the dimensions of the styled image.
  $dimensions = array(
    'width' => $variables['width'], 
    'height' => $variables['height'],
  );

  image_style_transform_dimensions($variables['style_name'], $dimensions);

  $variables['width'] = $dimensions['width'];
  $variables['height'] = $dimensions['height'];

  $variables['attributes'] = array(
    'class' => $variables['style_name'],
  );

  // Determine the url for the styled image.
  $variables['path'] = image_style_url($variables['style_name'], $variables['path']);
  return theme('image', $variables);
}

/**
 * Implements hook_form_alter().
 */
function odsherredsub_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#attributes']['placeholder'] = t('Hvad kan vi hjælpe med?');
  }

}

function odsherredsub_date_nav_title($params) {
  $granularity = $params['granularity'];
  $view = $params['view'];
  $date_info = $view->date_info;
  $link = !empty($params['link']) ? $params['link'] : FALSE;
  $format = !empty($params['format']) ? $params['format'] : NULL;
  $day = date_format_date($date_info->min_date, 'custom', "D d.");
  $month = strtolower(date_format_date($date_info->min_date, 'custom', "F"));
  $year = date_format_date($date_info->min_date, 'custom', "Y");
  switch ($granularity) {
    case 'year':
      $title = $date_info->year;
      $date_arg = $date_info->year;
      break;
    case 'month':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? 'F Y' : 'F');
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month);
      break;
    case 'day':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? 'D d. F Y' : 'D d. F Y');
      $title =  $day . " " . $month . " " . $year;
      $date_arg = $date_info->year . '-' . date_pad($date_info->month) . '-' . date_pad($date_info->day);
      break;
    case 'week':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? 'F j, Y' : 'F j');
      $title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', "d.") . " " . $month . " " . $year));
      $date_arg = $date_info->year . '-W' . date_pad($date_info->week);
      break;
  }
  if (!empty($date_info->mini) || $link) {
    // Month navigation titles are used as links in the mini view.
    $attributes = array('title' => t('View full page month'));
    $url = date_pager_url($view, $granularity, $date_arg, TRUE);
    return l($title, $url, array('attributes' => $attributes));
  }
  else {
    return $title;
  }
}

