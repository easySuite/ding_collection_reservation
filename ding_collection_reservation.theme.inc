<?php
/**
 * @file
 * Theme code for collection reservation.
 */

/**
 * Implements template_preprocess_ting_object(&$variables).
 */
function ding_collection_reservation_preprocess_ting_object(&$variables) {
  // Add button to each collection
  $multiple = (count($variables['elements']['#object']->ting_entities['und']) > 1);
  if ($variables['elements']['#view_mode'] == 'teaser' && variable_get('ting_reservable_collections', FALSE) && $multiple) {
    $link = url('ting/collection/' . $variables['elements']['#object']->ding_entity_id . '/popup/nojs');
    $markup = '<div class="field-type-ding-entity-buttons field-name-ding-entity-buttons">
                  <div class="reservation-link-ajax">
                    <a href="' . $link . '" class="use-ajax btn reserve-button reservable reservation collection">' .
                      t('Reserve') .
                    '</a>
                  </div>
                </div>
                <span id="collection_items"></span>';
    $variables['elements']['group_collection_object']['buttons']['#weight'] = 100;
    $variables['elements']['group_collection_object']['buttons']['#markup'] = $markup;

    // Load drupal ajax library for ding_popup
    drupal_add_library('system', 'drupal.ajax');
  }
}
