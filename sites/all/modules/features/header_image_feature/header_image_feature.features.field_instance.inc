<?php
/**
 * @file
 * header_image_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function header_image_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-header_image-field_header_image'
  $field_instances['node-header_image-field_header_image'] = array(
    'bundle' => 'header_image',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkout_pane' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_header_image',
    'label' => 'Header image',
    'required' => FALSE,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'allowed_types' => array(
          0 => 'image',
        ),
        'browser_plugins' => array(),
      ),
      'type' => 'media_generic',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Header image');

  return $field_instances;
}
