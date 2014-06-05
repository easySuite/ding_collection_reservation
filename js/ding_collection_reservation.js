/**
 * @file Handle show of reserve buttons in popup
 */
(function($) {
  $(document).on('dialogopen', function(event, ui) {
    var reserve_buttons_ids = [];

    $('.ding-popup-content .reserve-button').each(function() {
      reserve_buttons_ids.push($(this).attr('id').split(':'));
    });

    $.each(reserve_buttons_ids, function(id, content_id) {
      if (Drupal.DADB[content_id[1]].reservable) {
        $('.field-type-ding-entity-buttons a.reserve-button[id$="' + content_id[1] + '"]').addClass('reservable');
      }
    });
  });
})(jQuery);
