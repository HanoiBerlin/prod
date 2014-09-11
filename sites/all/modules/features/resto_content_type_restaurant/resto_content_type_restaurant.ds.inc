<?php
/**
 * @file
 * resto_content_type_restaurant.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function resto_content_type_restaurant_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resto_restaurant|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resto_restaurant';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_restaurant_contact',
        2 => 'field_restaurant_address',
        3 => 'field_restaurant_images',
        4 => 'field_restaurant_opening_hours',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_restaurant_contact' => 'ds_content',
      'field_restaurant_address' => 'ds_content',
      'field_restaurant_images' => 'ds_content',
      'field_restaurant_opening_hours' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|resto_restaurant|default'] = $ds_layout;

  return $export;
}
