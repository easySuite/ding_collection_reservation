/**
 * @file Handle show of reserve buttons in popup
 */
(function ($) {
  'use strict';
  Drupal.behaviors.ding_collection_reservation = {
    attach: function (context) {
      // Detect collection's reserveability.
      let found = [];
      let selector = '.js-check-collection-reservability';
      // Collect collection object id's from attributes.
      $(selector, context).once('js-check-collection-reservability', function () {
        let $this = this;
        let items = $($this, selector).parent().parent().parent().parent().parent().attr('ting-collection-items');
        if (items) {
          found.push(items);
        }
      });

      // Clean strings, transform and push for processing.
      let dataForProcessing = [];
      $.each(found, function (index, value) {
        // Remove unwanted "[" and "]" characters and transform string to array.
        let dataArray = value.substring(1, value.length - 1).split(',');

        let cleaned = [];
        // Remove quotes wrapping the array values.
        $.each(dataArray, function (i, v) {
          let cleanVal = v.substring(1, v.length - 1);
          cleaned.push(cleanVal);
        });

        dataForProcessing.push({
          'primary': cleaned[0],
          'data': cleaned
        });
      });

      if (dataForProcessing.length) {
        dataForProcessing.forEach(function (collection) {
          $.ajax({
            dataType: 'json',
            type: 'POST',
            url: '/ding_reservation/is_reservable',
            data: {
              localIds: collection.data
            },
            success: function (result) {
              let resultData = [];
              $.each(result, function (localId, reservable) {
                if (reservable) {
                  resultData.push(reservable);
                }
              });

              if (resultData.length > 0) {
                $(selector + '[data-local-id="' + collection.primary + '"]', context).addClass('reservable');
              }
            }
          });
        });
      }

      let observer = new MutationObserver(function (mutations) {
        mutations.forEach(function (mutation) {
          if (mutation.attributeName === "class" && $(mutation.target).hasClass('popupbar-is-open')) {
            $('#popupbar-collection_reservation').find('.reserve-button').each(function () {
              let local_id = $(this).attr('data-local-id');
              if (Drupal.DADB[local_id].reservable) {
                $(this).addClass('reservable');
              }
            });
          }
        });
      });

      let $body = $("body", context);
      if ($body[0]) {
        observer.observe($body[0], {attributes: true});
      }
    }
  };
})(jQuery);
