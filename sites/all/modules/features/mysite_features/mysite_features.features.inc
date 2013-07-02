<?php
/**
 * @file
 * mysite_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function mysite_features_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mysite_features_node_info() {
  $items = array(
    'image' => array(
      'name' => t('Image'),
      'base' => 'node_content',
      'description' => t('An image'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
