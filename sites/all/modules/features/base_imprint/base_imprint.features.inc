<?php
/**
 * @file
 * base_imprint.features.inc
 */

/**
 * Implements hook_node_info().
 */
function base_imprint_node_info() {
  $items = array(
    'impressum' => array(
      'name' => t('Impressum'),
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
