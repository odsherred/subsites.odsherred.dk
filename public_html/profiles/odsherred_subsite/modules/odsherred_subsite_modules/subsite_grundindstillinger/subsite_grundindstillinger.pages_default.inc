<?php

/**
 * @file
 * subsite_grundindstillinger.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function subsite_grundindstillinger_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Indholdselement fra Indholdselement (på Indholdselement: Spotbokse [field_spotbokse])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_spotbokse-node-node',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'odsherred_3stack';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right_top' => NULL,
      'right_middle' => NULL,
      'right_bottom' => NULL,
      'lead' => NULL,
      'middle_top' => NULL,
      'middle_center' => NULL,
      'middle_right' => NULL,
      'stack1' => NULL,
      'stack2' => NULL,
      'stack3' => NULL,
      'stack4' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '3932469f-bd6b-42bb-86da-4793cb9f4300';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2c6159a0-9828-4182-b47d-4c6e897f729c';
  $pane->panel = 'stack1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Undskriv',
    'title' => '',
    'body' => '<a href="/print/%node:nid" target="_blank" title="Undskriv">Udskriv</a>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'float-right del-udskriv',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2c6159a0-9828-4182-b47d-4c6e897f729c';
  $display->content['new-2c6159a0-9828-4182-b47d-4c6e897f729c'] = $pane;
  $display->panels['stack1'][0] = 'new-2c6159a0-9828-4182-b47d-4c6e897f729c';
  $pane = new stdClass();
  $pane->pid = 'new-5e637302-ac59-48e0-aa76-22d79c005c37';
  $pane->panel = 'stack1';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'sidetitel',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5e637302-ac59-48e0-aa76-22d79c005c37';
  $display->content['new-5e637302-ac59-48e0-aa76-22d79c005c37'] = $pane;
  $display->panels['stack1'][1] = 'new-5e637302-ac59-48e0-aa76-22d79c005c37';
  $pane = new stdClass();
  $pane->pid = 'new-8dd6e5dd-17d4-472f-9640-22d02e58c1be';
  $pane->panel = 'stack1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_billede';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'slideshow',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'slideshow_image_style' => 'indholdsside',
      'slideshow_link' => '',
      'slideshow_caption' => '',
      'slideshow_caption_link' => '',
      'slideshow_fx' => 'fade',
      'slideshow_speed' => '1000',
      'slideshow_timeout' => '4000',
      'slideshow_order' => '',
      'slideshow_controls' => 0,
      'slideshow_pause' => 1,
      'slideshow_pager' => '',
      'slideshow_pager_image_style' => 'square_thumbnail',
      'slideshow_carousel_image_style' => 'square_thumbnail',
      'slideshow_carousel_visible' => '0',
      'slideshow_carousel_scroll' => '1',
      'slideshow_carousel_speed' => '500',
      'slideshow_carousel_vertical' => 0,
      'slideshow_carousel_circular' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'no-padding',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8dd6e5dd-17d4-472f-9640-22d02e58c1be';
  $display->content['new-8dd6e5dd-17d4-472f-9640-22d02e58c1be'] = $pane;
  $display->panels['stack1'][2] = 'new-8dd6e5dd-17d4-472f-9640-22d02e58c1be';
  $pane = new stdClass();
  $pane->pid = 'new-73244e2a-135a-4a43-aa76-8b714ff22488';
  $pane->panel = 'stack1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_alternativt_billede';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'indholdsside_alt',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '73244e2a-135a-4a43-aa76-8b714ff22488';
  $display->content['new-73244e2a-135a-4a43-aa76-8b714ff22488'] = $pane;
  $display->panels['stack1'][3] = 'new-73244e2a-135a-4a43-aa76-8b714ff22488';
  $pane = new stdClass();
  $pane->pid = 'new-d25893b6-de35-46fd-9154-10e904e704f1';
  $pane->panel = 'stack1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_field_resume_long';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'd25893b6-de35-46fd-9154-10e904e704f1';
  $display->content['new-d25893b6-de35-46fd-9154-10e904e704f1'] = $pane;
  $display->panels['stack1'][4] = 'new-d25893b6-de35-46fd-9154-10e904e704f1';
  $pane = new stdClass();
  $pane->pid = 'new-0cb4213a-e93b-4e92-9773-377e1e2eabec';
  $pane->panel = 'stack2';
  $pane->type = 'views_panes';
  $pane->subtype = 'selvbetjening-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'nid' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0cb4213a-e93b-4e92-9773-377e1e2eabec';
  $display->content['new-0cb4213a-e93b-4e92-9773-377e1e2eabec'] = $pane;
  $display->panels['stack2'][0] = 'new-0cb4213a-e93b-4e92-9773-377e1e2eabec';
  $pane = new stdClass();
  $pane->pid = 'new-d75348da-024e-4afd-87d2-8fd2e3d357cd';
  $pane->panel = 'stack2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_filer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'file_rendered',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Hent...',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd75348da-024e-4afd-87d2-8fd2e3d357cd';
  $display->content['new-d75348da-024e-4afd-87d2-8fd2e3d357cd'] = $pane;
  $display->panels['stack2'][1] = 'new-d75348da-024e-4afd-87d2-8fd2e3d357cd';
  $pane = new stdClass();
  $pane->pid = 'new-720c0961-a9c8-4339-85c0-f53da647bf0c';
  $pane->panel = 'stack3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'node-body',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '720c0961-a9c8-4339-85c0-f53da647bf0c';
  $display->content['new-720c0961-a9c8-4339-85c0-f53da647bf0c'] = $pane;
  $display->panels['stack3'][0] = 'new-720c0961-a9c8-4339-85c0-f53da647bf0c';
  $pane = new stdClass();
  $pane->pid = 'new-7bdff062-2d0d-403e-9189-ef11751d2478';
  $pane->panel = 'stack4';
  $pane->type = 'views_panes';
  $pane->subtype = 'spotbokse-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'nid' => '%node:nid',
    ),
    'override_title' => 0,
    'override_title_text' => '%node:nid',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7bdff062-2d0d-403e-9189-ef11751d2478';
  $display->content['new-7bdff062-2d0d-403e-9189-ef11751d2478'] = $pane;
  $display->panels['stack4'][0] = 'new-7bdff062-2d0d-403e-9189-ef11751d2478';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5e637302-ac59-48e0-aa76-22d79c005c37';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function subsite_grundindstillinger_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'forside';
  $page->task = 'page';
  $page->admin_title = 'Forside';
  $page->admin_description = '';
  $page->path = 'forside';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'weight' => '0',
    'name' => 'navigation',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_forside_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'forside';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'os2web_6_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Forside';
  $display->uuid = 'ba73f2c3-120a-4c32-ae1f-3b00ee117a48';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_forside_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-798a4371-d761-4791-8d4f-f6737c340d7e';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-os2web_velkomst-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hbg pad10 margin-bund-20',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '798a4371-d761-4791-8d4f-f6737c340d7e';
  $display->content['new-798a4371-d761-4791-8d4f-f6737c340d7e'] = $pane;
  $display->panels['left'][0] = 'new-798a4371-d761-4791-8d4f-f6737c340d7e';
  $pane = new stdClass();
  $pane->pid = 'new-67d0c6f3-ec7a-449d-9b1d-6c39a85dd2a4';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'seneste_ny';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '2',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hbg pad10',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '67d0c6f3-ec7a-449d-9b1d-6c39a85dd2a4';
  $display->content['new-67d0c6f3-ec7a-449d-9b1d-6c39a85dd2a4'] = $pane;
  $display->panels['left'][1] = 'new-67d0c6f3-ec7a-449d-9b1d-6c39a85dd2a4';
  $pane = new stdClass();
  $pane->pid = 'new-9890aeef-608c-472a-8201-56258d00e9ca';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'kontaktblok';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pad5 hbg margin-bund-20',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9890aeef-608c-472a-8201-56258d00e9ca';
  $display->content['new-9890aeef-608c-472a-8201-56258d00e9ca'] = $pane;
  $display->panels['right'][0] = 'new-9890aeef-608c-472a-8201-56258d00e9ca';
  $pane = new stdClass();
  $pane->pid = 'new-ee1c0b3e-c7e7-4474-b7fb-6ca48e359730';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'spotbokse';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pad5 hbg',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ee1c0b3e-c7e7-4474-b7fb-6ca48e359730';
  $display->content['new-ee1c0b3e-c7e7-4474-b7fb-6ca48e359730'] = $pane;
  $display->panels['right'][1] = 'new-ee1c0b3e-c7e7-4474-b7fb-6ca48e359730';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['forside'] = $page;

  return $pages;

}
