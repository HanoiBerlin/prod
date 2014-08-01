<?php
/**
 * @file
 * shipping.features.inc
 */

/**
 * Implements hook_commerce_shipping_service_info().
 */
function shipping_commerce_shipping_service_info() {
  $items = array(
    'freie_lieferung' => array(
      'name' => 'freie_lieferung',
      'base' => 'freie_lieferung',
      'display_title' => 'Freie Lieferung',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_freie_lieferung',
      'weight' => 0,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'freie_lieferung_details_form',
        'details_form_validate' => 'freie_lieferung_details_form_validate',
        'details_form_submit' => 'freie_lieferung_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Freie Lieferung',
      'base_rate' => array(
        'amount' => 0,
        'currency_code' => 'EUR',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
      'is_features' => TRUE,
    ),
    'lieferung' => array(
      'name' => 'lieferung',
      'base' => 'lieferung',
      'display_title' => 'Lieferung',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_lieferung',
      'weight' => 1,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'lieferung_details_form',
        'details_form_validate' => 'lieferung_details_form_validate',
        'details_form_submit' => 'lieferung_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Lieferung',
      'base_rate' => array(
        'amount' => 500,
        'currency_code' => 'EUR',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
      'is_features' => TRUE,
    ),
  );
  return $items;
}
