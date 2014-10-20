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
 * Implements hook_image_default_styles().
 */
function header_image_feature_image_default_styles() {
  $styles = array();

  // Exported image style: header_image.
  $styles['header_image'] = array(
    'name' => 'header_image',
    'label' => 'Header Image',
    'effects' => array(
      2 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 1920,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
