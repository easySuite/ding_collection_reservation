/**
 * @file Handle show of reserve buttons in popup
 */
(function($) {
  'use strict';
  Drupal.behaviors.ding_collection_reservation = {
    attach: function(context, settings) {
      let observer = new MutationObserver(function(mutations) {
        mutations.forEach(function (mutation) {
          if (mutation.attributeName === "class" && $(mutation.target).hasClass('popupbar-is-open')) {
            $('#popupbar-collection_reservation').find('.reserve-button').each(function() {
              let local_id = $(this).attr('id').split(':')[1];
              if (Drupal.DADB[local_id].reservable) {
                $(this).addClass('reservable');
              }
            });
          }
        })
      });

      let $body = $("body", context);
      if ($body[0]) {
        observer.observe($body[0], {attributes: true});
      }
    }
  };
})(jQuery);
