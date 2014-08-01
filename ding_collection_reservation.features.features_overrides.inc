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
  $overrides["field_instance.ting_collection-ting_collection-ting_collection_types.display|collection_popup"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 1,
  );
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
  $overrides["field_instance.ting_object-ting_object-ding_availability_holdings.display|objects_in_popup"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 18,
  );
  $overrides["field_instance.ting_object-ting_object-ding_entity_buttons.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ding_entity',
    'settings' => array(),
    'type' => 'ding_entity_buttons_ajax',
    'weight' => 3,
  );
  $overrides["field_instance.ting_object-ting_object-ting_author.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ting',
    'settings' => array(),
    'type' => 'ting_author_default',
    'weight' => 2,
  );
  $overrides["field_instance.ting_object-ting_object-ting_cover.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ting_covers_plus',
    'settings' => array(
      'image_style' => 'medium',
    ),
    'type' => 'ting_cover_default',
    'weight' => 0,
  );
  $overrides["field_instance.ting_object-ting_object-ting_details_age.display|objects_in_popup"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 39,
  );
  $overrides["field_instance.ting_object-ting_object-ting_title.display|objects_in_popup"] = array(
    'label' => 'hidden',
    'module' => 'ting',
    'settings' => array(
      'link_type' => 'none',
      'prefix_type' => 'no',
    ),
    'type' => 'ting_title_default',
    'weight' => 1,
  );

 return $overrides;
}
