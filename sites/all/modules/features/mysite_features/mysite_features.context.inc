<?php
/**
 * @file
 * mysite_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function mysite_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contextes_de_mon_site';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-gallery-block_1' => array(
          'module' => 'views',
          'delta' => 'gallery-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['contextes_de_mon_site'] = $context;

  return $export;
}
