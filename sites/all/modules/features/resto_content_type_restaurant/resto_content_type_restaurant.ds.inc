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
        0 => 'title',
        1 => 'body',
        2 => 'field_restaurant_images',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_restaurant_images' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|resto_restaurant|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resto_restaurant|footer';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resto_restaurant';
  $ds_layout->view_mode = 'footer';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_restaurant_address',
        2 => 'field_office_hours',
      ),
      'right' => array(
        3 => 'field_geofield',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_restaurant_address' => 'left',
      'field_office_hours' => 'left',
      'field_geofield' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|resto_restaurant|footer'] = $ds_layout;

  return $export;
}
