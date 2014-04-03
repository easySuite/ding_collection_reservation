<?php

/**
 * Preprocess template for ting object
 * @param $variables
 */
function ding_collection_reservation_preprocess_ting_object(&$variables) {

  //Add button to each collection
  $multiple = (count($variables['elements']['#object']->ting_entities['und']) > 1);
  if ($variables['elements']['#view_mode'] == 'teaser' && variable_get('ting_reservable_collections', FALSE) && $multiple) {
    $variables['elements']['group_collection_object']['buttons']['#weight'] = 100;
    $variables['elements']['group_collection_object']['buttons']['#markup'] = '<div class="field-type-ding-entity-buttons">';
    $link = url('ting/collection/' . $variables['elements']['#object']->ding_entity_id . '/popup/nojs');
    $variables['elements']['group_collection_object']['buttons']['#markup'] .= '<div class="reservation-link-ajax"><a href="' . $link . '" class="use-ajax btn reservation collection">' . t('Reserve') . '</a></div>';
    $variables['elements']['group_collection_object']['buttons']['#markup'] .= '</div><span id="collection_items"></span>';
  }
}
