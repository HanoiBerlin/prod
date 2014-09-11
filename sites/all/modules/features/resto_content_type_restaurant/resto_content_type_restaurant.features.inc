<?php
/**
 * @file
 * resto_content_type_restaurant.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function resto_content_type_restaurant_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function resto_content_type_restaurant_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function resto_content_type_restaurant_node_info() {
  $items = array(
    'resto_restaurant' => array(
      'name' => t('Restaurant'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a restaurant location with all necessary data.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
