<?php
/**
 * @file
 * food_categories_and_ctt.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function food_categories_and_ctt_commerce_product_default_types() {
  $items = array(
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'A basic product type.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function food_categories_and_ctt_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function food_categories_and_ctt_node_info() {
  $items = array(
    'food' => array(
      'name' => t('Food'),
      'base' => 'node_content',
      'description' => t('Use this to add food items to your offer'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
