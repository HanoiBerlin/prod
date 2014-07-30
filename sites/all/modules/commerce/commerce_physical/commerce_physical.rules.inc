<?php

/**
 * Implements hook_rules_condition_info().
 */
function commerce_physical_rules_condition_info() {

  $conditions = array();

  $conditions['commerce_physical_rules_order_is_under_weight_limit'] = array(
    'label' => t("Order's total weight is under a chosen limit"),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'limit' => array(
        'type' => 'decimal',
        'label' => t('Weight limit (kg)'),
      ),
    ),
    'group' => t('Commerce Physical'),
    'callbacks' => array(
      'execute' => 'commerce_physical_rules_order_is_under_weight_limit',
    ),
  );

  $conditions['commerce_physical_rules_order_maximum_dimension_is_under_size'] = array(
    'label' => t("The maximum dimension of any product in the order is under a certain size"),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'limit' => array(
        'type' => 'decimal',
        'label' => t('Size limit (cm)'),
      ),
    ),
    'group' => t('Commerce Physical'),
    'callbacks' => array(
      'execute' => 'commerce_physical_rules_order_maximum_dimension_is_under_size',
    ),
  );

  return $conditions;
}

/**
 * Rules condition: checks to see if the maximum dimension of any product in the
 * order is under a certain size
 */
function commerce_physical_rules_order_maximum_dimension_is_under_size($order, $limit) {

  $max_dimension = 0;

  $dimension_keys = array(
    'length',
    'width',
    'height',
  );

  // Get the dimensions of every product in the order
  foreach (commerce_physical_order_dimensions($order, 'cm') as $dimension) {

    // Check each of length / width / height
    foreach ($dimension_keys as $dimension_key) {

      // If this dimension's bigger than the current max, it's the new max.
      if ($dimension[$dimension_key] > $max_dimension) {
        $max_dimension = $dimension[$dimension_key];
      }
    }
  }

  if ($max_dimension > $limit) {
    // Total size is over the limit. This condition fails:
    return FALSE;
  }

  // Otherwise, this condition passes:
  return TRUE;
}

/**
 * Rules condition: checks to see if the given order's total weight is under a
 * certain limit.
 */
function commerce_physical_rules_order_is_under_weight_limit($order, $limit) {

  $order_weight = commerce_physical_order_weight($order, 'kg');

  if ($order_weight['weight'] > $limit) {
    // Total weight is over the limit. This condition fails:
    return FALSE;
  }

  // Otherwise, this condition passes:
  return TRUE;
}
