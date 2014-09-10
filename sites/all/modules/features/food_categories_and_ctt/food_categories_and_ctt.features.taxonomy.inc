<?php
/**
 * @file
 * food_categories_and_ctt.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function food_categories_and_ctt_taxonomy_default_vocabularies() {
  return array(
    'food_categories' => array(
      'name' => 'Food Categories',
      'machine_name' => 'food_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
