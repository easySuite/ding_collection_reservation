<?php
/**
 * @file
 * ding_collection_reservation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ding_collection_reservation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function ding_collection_reservation_field_default_field_instances_alter(&$data) {
  if (isset($data['ting_collection-ting_collection-ting_entities'])) {
    $data['ting_collection-ting_collection-ting_entities']['display']['collection_popup'] = array(
      'label' => 'hidden',
      'module' => 'ting',
      'settings' => array(
        'hide_primary' => 0,
        'view_mode' => 'objects_in_popup',
      ),
      'type' => 'ting_entities_default',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ding_entity_buttons'])) {
    $data['ting_object-ting_object-ding_entity_buttons']['display']['objects_in_popup'] = array(
      'label' => 'hidden',
      'module' => 'ding_entity',
      'settings' => array(),
      'type' => 'ding_entity_buttons_ajax',
      'weight' => 5,
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_cover'])) {
    $data['ting_object-ting_object-ting_cover']['display']['objects_in_popup'] = array(
      'label' => 'hidden',
      'module' => 'ting_covers',
      'settings' => array(
        'image_style' => 'ding_list_medium',
        'link_type' => 'none',
      ),
      'type' => 'ting_cover_default',
      'weight' => 1,
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_title'])) {
    $data['ting_object-ting_object-ting_title']['display']['objects_in_popup'] = array(
      'label' => 'hidden',
      'module' => 'ting',
      'type' => 'ting_title_default',
      'weight' => 3,
    ); /* WAS: '' */
  }
}
