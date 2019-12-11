<?php
/**
 * @file
 * ding_collection_reservation.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function ding_collection_reservation_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.ting_collection-ting_collection-ting_entities.display|collection_popup"] = array(
    'label' => 'hidden',
    'module' => 'ting',
    'settings' => array(
      'hide_primary' => 0,
      'view_mode' => 'objects_in_popup',
    ),
    'type' => 'ting_entities_default',
    'weight' => 0,
  );
  $overrides["field_instance.ting_object-ting_object-ding_entity_buttons.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ding_entity',
    'settings' => array(),
    'type' => 'ding_entity_buttons_ajax',
    'weight' => 5,
  );
  $overrides["field_instance.ting_object-ting_object-ting_author.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ting',
    'type' => 'ting_author_default',
    'weight' => 4,
  );
  $overrides["field_instance.ting_object-ting_object-ting_cover.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ting_covers',
    'settings' => array(
      'image_style' => 'ding_list_medium',
      'link_type' => 'none',
    ),
    'type' => 'ting_cover_default',
    'weight' => 1,
  );
  $overrides["field_instance.ting_object-ting_object-ting_title.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ting',
    'type' => 'ting_title_default',
    'weight' => 3,
  );

 return $overrides;
}
