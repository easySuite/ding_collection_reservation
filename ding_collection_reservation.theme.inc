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
    $link = 'ting/collection/' . $variables['elements']['#object']->ding_entity_id . '/popup/nojs';
    $attributes = array(
      'attributes' => array(
        'class' => array(
          'use-ajax',
          'reserve-button',
          'btn',
          'reservation',
          'collection',
          'action-button',
        ),
      ),
    );
    $variables['elements']['ting_primary_object'][0]['ding_entity_buttons'] = array(
      '#markup' => l(t('Reserve'), $link, $attributes),
      '#prefix' => '<div class="field-type-ding-entity-buttons field-name-ding-entity-buttons"><div class="reservation-link-ajax">',
      '#suffix' => '</div></div><span id="collection_items"></span>',
      '#weight' => 100,
    );

    // Load drupal ajax library for ding_popup
    drupal_add_library('system', 'drupal.ajax');
  }
  elseif ($multiple) {
    $buttons = &$variables['elements']['ting_primary_object'][0]['ding_entity_buttons'][0];
    foreach ($buttons as &$button) {
      // TODO: Get a proper way to find Reservation button.
      $found = preg_match('/(Res)/', $button['#text']);
      if (!empty($button['#text']) && $found) {
        $button['#options']['attributes']['class'][] = 'collection-hidden';
      }
    }
  }
}
