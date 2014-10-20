<?php
/**
 * @file
 * header_image_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function header_image_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer header image'.
  $permissions['administer header image'] = array(
    'name' => 'administer header image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'headerimage',
  );

  // Exported permission: 'maintain display conditions'.
  $permissions['maintain display conditions'] = array(
    'name' => 'maintain display conditions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'headerimage',
  );

  // Exported permission: 'view header image'.
  $permissions['view header image'] = array(
    'name' => 'view header image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'headerimage',
  );

  return $permissions;
}
