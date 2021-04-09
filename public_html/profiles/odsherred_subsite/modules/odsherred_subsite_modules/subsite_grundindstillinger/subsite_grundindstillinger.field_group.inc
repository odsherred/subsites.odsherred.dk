<?php

/**
 * @file
 * subsite_grundindstillinger.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function subsite_grundindstillinger_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_billeder|node|page|form';
  $field_group->group_name = 'group_billeder';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indholdsside';
  $field_group->data = array(
    'label' => 'Billeder og filer',
    'weight' => '3',
    'children' => array(
      0 => 'field_billede',
      1 => 'field_alternativt_billede',
      2 => 'field_filer',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-billeder field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_billeder|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_extras|node|page|form';
  $field_group->group_name = 'group_extras';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indholdsside';
  $field_group->data = array(
    'label' => 'Emneord',
    'weight' => '4',
    'children' => array(
      0 => 'field_tags',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-extras field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_extras|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|page|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indholdsside';
  $field_group->data = array(
    'label' => 'Generelt',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_field_resume_long',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-general field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gruppe3|node|page|form';
  $field_group->group_name = 'group_gruppe3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indholdsside';
  $field_group->data = array(
    'label' => 'Indstillinger',
    'weight' => '5',
    'children' => array(
      0 => 'field_selvbetjeninger',
      1 => 'field_spotbokse',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-gruppe3 field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_gruppe3|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_indholdsside|node|page|form';
  $field_group->group_name = 'group_indholdsside';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Indholdsside',
    'weight' => '1',
    'children' => array(
      0 => 'group_general',
      1 => 'group_billeder',
      2 => 'group_extras',
      3 => 'group_gruppe3',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-indholdsside field-group-htabs',
        'id' => 'node_page_form_group_indholdsside',
      ),
    ),
  );
  $field_groups['group_indholdsside|node|page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Billeder og filer');
  t('Emneord');
  t('Generelt');
  t('Indholdsside');
  t('Indstillinger');

  return $field_groups;
}
