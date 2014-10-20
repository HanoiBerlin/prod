<?php
/**
 * @file
 * header_image_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function header_image_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function header_image_feature_node_info() {
  $items = array(
    'header_image' => array(
      'name' => t('Header Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
