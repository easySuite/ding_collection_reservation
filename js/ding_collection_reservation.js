/**
 * @file Handle show of reserve buttons in popup
 */
(function($) {
  $(document).on('dialogopen', function(event, ui) {
    $('.ding-popup-content .reserve-button').each(function() {
      $(this).show();
    });
  });
})(jQuery);
