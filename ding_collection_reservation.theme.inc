<?php
/**
 * @file
 * Theme code for collection reservation.
 */

/**
 * Implements template_preprocess_ting_object(&$variables).
 */
function ding_collection_reservation_preprocess_ting_object(&$variables) {
  $ting_entities = $variables['elements']['#object']->ting_entities;
  // Add button to each collection.
  $multiple = ($ting_entities && is_array($ting_entities[LANGUAGE_NONE]) && count($ting_entities[LANGUAGE_NONE]) > 1);
  $variables['elements']['#attached']['js'][] = drupal_get_path('module', 'ding_collection_reservation') . '/js/ding_collection_reservation.js';
  if ($variables['elements']['#view_mode'] == 'teaser' && $multiple && variable_get('ting_reservable_collections', FALSE)) {
    $items = [];
    $local_id = NULL;
    if ($variables['elements']['#object'] instanceof TingCollection) {
      $collection = $variables['elements']['#object'];
      $entities = $collection->getEntities();

      /** @var \TingEntity $entity */
      foreach ($entities as $key => $entity) {
        $items[] = $entity->getLocalId();
      }

      $primaryObject = $collection->getPrimary_object();
      $local_id = $primaryObject->getLocalId();
    }

    $variables['attributes_array']['ting-collection-items'] = drupal_json_encode($items);
    $link = 'ting/collection/' . $variables['elements']['#object']->ding_entity_id . '/popup/nojs';
    $attributes = [
      'attributes' => [
        'class' => [
          'use-ajax',
          'reserve-button',
          'btn',
          'reservation',
          'collection',
          'action-button',
          'js-check-collection-reservability',
        ],
      ],
    ];

    if (!empty($local_id)) {
      $attributes['attributes']['data-local-id'] = $local_id;
    }

    $variables['elements']['ting_primary_object'][0]['ding_entity_buttons'] = [
      '#markup' => l(t('Reserve'), $link, $attributes),
      '#prefix' => '<div class="field-type-ding-entity-buttons field-name-ding-entity-buttons"><div class="reservation-link-ajax">',
      '#suffix' => '</div></div><span id="collection_items"></span>',
      '#weight' => 100,
    ];

    // Load drupal ajax library for ding_popup.
    drupal_add_library('system', 'drupal.ajax');
  }
  elseif ($multiple && isset($variables['elements']['ting_primary_object'][0]['ding_entity_buttons'])) {
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
