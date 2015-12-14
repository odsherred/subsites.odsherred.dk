<?php
function cmstheme_skinr_skin_grid_info() {

  $skins = array();

  $skins['grid_gridwidth'] = array(
    'title' => t('Grid Width'),
    'description' => t('None'),
    'type' => 'select',
    'default status' => TRUE,
    'options' => array(
      'grid_1' => array('title' => t('Grid 1'), 'class' => array('grid-1')),
      'grid_2' => array('title' => t('Grid 2'), 'class' => array('grid-2')),
      'grid_3' => array('title' => t('Grid 3'), 'class' => array('grid-3')),
      'grid_4' => array('title' => t('Grid 4'), 'class' => array('grid-4')),
      'grid_5' => array('title' => t('Grid 5'), 'class' => array('grid-5')),
      'grid_6' => array('title' => t('Grid 6'), 'class' => array('grid-6')),
      'grid_7' => array('title' => t('Grid 7'), 'class' => array('grid-7')),
      'grid_8' => array('title' => t('Grid 8'), 'class' => array('grid-8')),
      'grid_9' => array('title' => t('Grid 9'), 'class' => array('grid-9')),
      'grid_10' => array('title' => t('Grid 10'), 'class' => array('grid-10')),
      'grid_11' => array('title' => t('Grid 11'), 'class' => array('grid-11')),
      'grid_12' => array('title' => t('Grid 12'), 'class' => array('grid-12')),
      'grid_13' => array('title' => t('Grid 13'), 'class' => array('grid-13')),
      'grid_14' => array('title' => t('Grid 14'), 'class' => array('grid-14')),
      'grid_15' => array('title' => t('Grid 15'), 'class' => array('grid-15')),
      'grid_16' => array('title' => t('Grid 16'), 'class' => array('grid-16')),
      'grid_17' => array('title' => t('Grid 17'), 'class' => array('grid-17')),
      'grid_18' => array('title' => t('Grid 18'), 'class' => array('grid-18')),
      'grid_19' => array('title' => t('Grid 19'), 'class' => array('grid-19')),
      'grid_20' => array('title' => t('Grid 20'), 'class' => array('grid-20')),
      'grid_21' => array('title' => t('Grid 21'), 'class' => array('grid-21')),
      'grid_22' => array('title' => t('Grid 22'), 'class' => array('grid-22')),
      'grid_23' => array('title' => t('Grid 23'), 'class' => array('grid-23')),
      'grid_24' => array('title' => t('Grid 24'), 'class' => array('grid-24')),
    ),
  );
  $skins['grid_alpha'] = array(
    'title' => t('Format Alpha'),
    'description' => t('None'),
    'type' => 'checkboxes',
    'default status' => TRUE,
    'options' => array(
      'inline' => array('title' => t('Alpha'), 'class' => array('alpha')),
    ),
  );
  $skins['grid_omega'] = array(
    'title' => t('Format Omega'),
    'description' => t('None'),
    'type' => 'checkboxes',
    'default status' => TRUE,
    'options' => array(
      'inline' => array('title' => t('Omega'), 'class' => array('omega')),
    ),
  );
  return $skins;
}
?>
