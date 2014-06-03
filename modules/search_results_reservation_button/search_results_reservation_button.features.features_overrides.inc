<?php
/**
 * @file
 * search_results_reservation_button.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function search_results_reservation_button_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_group
  $overrides["field_group.group_ting_right_col_search|ting_object|ting_object|search_result.data|children|0"] = 'ting_title';
  $overrides["field_group.group_ting_right_col_search|ting_object|ting_object|search_result.data|children|1"] = 'ting_series';
  $overrides["field_group.group_ting_right_col_search|ting_object|ting_object|search_result.data|children|2"] = 'ting_abstract';
  $overrides["field_group.group_ting_right_col_search|ting_object|ting_object|search_result.data|children|3"] = 'ting_author';
  $overrides["field_group.group_ting_right_col_search|ting_object|ting_object|search_result.data|children|4"] = 'ding_entity_buttons';

  // Exported overrides for: field_instance
  $overrides["field_instance.ting_object-ting_object-ding_entity_buttons.display|search_result|label"] = 'hidden';
  $overrides["field_instance.ting_object-ting_object-ding_entity_buttons.display|search_result|module"] = 'ding_entity';
  $overrides["field_instance.ting_object-ting_object-ding_entity_buttons.display|search_result|type"] = 'ding_entity_buttons_ajax';
  $overrides["field_instance.ting_object-ting_object-ding_entity_buttons.display|search_result|weight"] = 99;

 return $overrides;
}
