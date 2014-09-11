<?php
/**
 * @file
 * food_categories_and_ctt.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function food_categories_and_ctt_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'menu';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Menu';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Menu';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_food_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'commerce_price' => 'commerce_price',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_food_product_target_id']['id'] = 'field_food_product_target_id';
  $handler->display->display_options['relationships']['field_food_product_target_id']['table'] = 'field_data_field_food_product';
  $handler->display->display_options['relationships']['field_food_product_target_id']['field'] = 'field_food_product_target_id';
  /* Field: Content: Food Category */
  $handler->display->display_options['fields']['field_food_category']['id'] = 'field_food_category';
  $handler->display->display_options['fields']['field_food_category']['table'] = 'field_data_field_food_category';
  $handler->display->display_options['fields']['field_food_category']['field'] = 'field_food_category';
  $handler->display->display_options['fields']['field_food_category']['label'] = '';
  $handler->display->display_options['fields']['field_food_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_food_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_food_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_food_product_target_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Content: Food Description */
  $handler->display->display_options['fields']['field_food_description']['id'] = 'field_food_description';
  $handler->display->display_options['fields']['field_food_description']['table'] = 'field_data_field_food_description';
  $handler->display->display_options['fields']['field_food_description']['field'] = 'field_food_description';
  $handler->display->display_options['fields']['field_food_description']['label'] = '';
  $handler->display->display_options['fields']['field_food_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_food_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_food_description']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_food_product_target_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'product';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'food' => 'food',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'menu';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Menu';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['menu'] = array(
    t('Master'),
    t('Menu'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Commerce Product entity referenced from field_food_product'),
    t('Page'),
  );
  $export['menu'] = $view;

  return $export;
}
