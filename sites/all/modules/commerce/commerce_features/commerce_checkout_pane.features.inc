<?php

/**
 * Implements hook_features_export().
 */
function commerce_checkout_pane_features_export($data, &$export, $module_name = '') {
  // Add required dependencies.
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['commerce_checkout'] = 'commerce_checkout';

  $panes = commerce_checkout_panes();
  foreach ($data as $pane_id) {
    $export['features']['commerce_checkout_pane'][$pane_id] = $pane_id;
    $module = $panes[$pane_id]['module'];
    $export['dependencies'][$module] = $module;
  }
  return array();
}

/**
 * Implements hook_features_export_options().
 */
function commerce_checkout_pane_features_export_options() {
  $feature_panes = array();
  foreach (commerce_checkout_panes() as $pane_id => $pane) {
    $feature_panes[$pane_id] = $pane['title'];
  }
  return $feature_panes;
}

/**
 * Implements hook_features_export_render().
 */
function commerce_checkout_pane_features_export_render($module, $data, $export = NULL) {
  $output = array();
  $panes = commerce_checkout_panes();
  $exportable_keys = array_fill_keys(array(
    'pane_id',
    'page',
    'fieldset',
    'collapsible',
    'collapsed',
    'weight',
    'enabled',
    'review',
  ), 1);
  $output[] = '  $panes = array();';
  foreach ($data as $pane_id) {
    if (isset($panes[$pane_id])) {
      $exportable_pane = array_intersect_key($panes[$pane_id], $exportable_keys);
      $output[] = '';
      $output[] = "  \$panes['{$pane_id}'] = " . features_var_export($exportable_pane, '  ') . ";";
    }
  }
  $output[] = '';
  $output[] = '  return $panes;';
  $output = implode("\n", $output);
  return array('commerce_features_default_checkout_panes' => $output);
}

/**
 * Implements hook_features_revert().
 */
function commerce_checkout_pane_features_revert($module = NULL) {
  $panes = commerce_checkout_panes(array(), FALSE, TRUE);
  if (module_hook($module, 'commerce_features_default_checkout_panes')) {
    $default_panes = module_invoke($module, 'commerce_features_default_checkout_panes');
    foreach ($default_panes as $pane_id => $default_pane) {
      if (!empty($panes[$pane_id])) {
        $default_pane['saved'] = !empty($panes[$pane_id]['saved']);
        commerce_checkout_pane_save($default_pane);
      }
    }
  }
  else {
    drupal_set_message(t('Could not load default checkout panes.'), 'error');
    return FALSE;
  }
  return TRUE;
}

/**
 * Implements hook_features_rebuild().
 */
function commerce_checkout_pane_features_rebuild($module) {
  return commerce_checkout_pane_features_revert($module);
}

/**
 * Implements hook_features_enable_feature().
 */
function commerce_checkout_pane_features_enable_feature($module) {
  commerce_checkout_pane_features_revert($module);
}

/**
 * Implements hook_features_disable_feature().
 */
function commerce_checkout_pane_features_disable_feature($module) {
  if (module_hook($module, 'commerce_features_default_checkout_panes')) {
    $default_panes = module_invoke($module, 'commerce_features_default_checkout_panes');
    foreach ($default_panes as $pane_id => $default_pane) {
      commerce_checkout_pane_reset($pane_id);
    }
  }
}
