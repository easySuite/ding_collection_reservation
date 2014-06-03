<?php
/**
 * @file
 * search_results_reservation_button.features.inc
 */

/**
 * Implements hook_field_group_info_alter().
 */
function search_results_reservation_button_field_group_info_alter(&$data) {
  if (isset($data['group_ting_right_col_search|ting_object|ting_object|search_result'])) {
    $data['group_ting_right_col_search|ting_object|ting_object|search_result']->data['children']['0'] = 'ting_title'; /* WAS: 'ting_title' */
    $data['group_ting_right_col_search|ting_object|ting_object|search_result']->data['children']['1'] = 'ting_series'; /* WAS: 'ting_series' */
    $data['group_ting_right_col_search|ting_object|ting_object|search_result']->data['children']['2'] = 'ting_abstract'; /* WAS: 'ting_abstract' */
    $data['group_ting_right_col_search|ting_object|ting_object|search_result']->data['children']['3'] = 'ting_author'; /* WAS: 'ting_author' */
    $data['group_ting_right_col_search|ting_object|ting_object|search_result']->data['children']['4'] = 'ding_entity_buttons'; /* WAS: '' */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function search_results_reservation_button_field_default_field_instances_alter(&$data) {
  if (isset($data['ting_object-ting_object-ding_entity_buttons'])) {
    $data['ting_object-ting_object-ding_entity_buttons']['display']['search_result']['label'] = 'hidden'; /* WAS: 'above' */
    $data['ting_object-ting_object-ding_entity_buttons']['display']['search_result']['module'] = 'ding_entity'; /* WAS: '' */
    $data['ting_object-ting_object-ding_entity_buttons']['display']['search_result']['type'] = 'ding_entity_buttons_ajax'; /* WAS: 'hidden' */
    $data['ting_object-ting_object-ding_entity_buttons']['display']['search_result']['weight'] = 99; /* WAS: 37 */
  }
}
