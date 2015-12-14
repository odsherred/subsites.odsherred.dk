(function ($) {
  Drupal.behaviors.os2web_mobile_theme_sub = {
    attach: function (context, settings) {

      $('article img').each(function(){
        if($(this).width() > $(window).width()){
	      $(this).width($(window).width());
	    }
      });

      $('.node-contentpage iframe').remove();

      $('.view-meetings-search .form-type-date-popup.form-item').on('click', function(event){
        $input = $(this).find('input');
        $input.datepicker({dateFormat: "yy-mm-dd"}).datepicker("show");
      });

      $('a[href^="#"]').on('click',function(event){
          event.preventDefault();
          var target_offset = $(this.hash).offset() ? $(this.hash).offset().top : 0;
          //change this number to create the additional off set        
          var customoffset = 100;
          $('html, body').animate({scrollTop:target_offset - customoffset}, 500);
      });
      
      function meeting_bullets(){
        var is_visible = false;
        $('.agenda-item').hide();
        $('a.agenda-bullet-list').click(function(e) {
        e.preventDefault();
        $(this).nextAll('.agenda-item').toggle();
        $(this).toggleClass('open');
        $('a.agenda-bullet-list').not(this).nextAll('.agenda-item').hide();
        $('a.agenda-bullet-list').not(this).removeClass('open');
        var top = $(this).nextAll('.agenda-item').offset().top;
        window.scrollTo(0, top -50);
        });
      }

      if($('.agenda-item').length){
        $('.agenda-item article').width($('.view-meeting-details').width() - 50);

        $('.agenda-item ul li article a').removeAttr('href');
        
        meeting_bullets();
      }
    }
  };
}(jQuery));

(function($){
  $(window).resize(function() {

    var width = jQuery('.views_slideshow_cycle_main').width();
    var ratio = (jQuery('.views-slideshow-cycle-main-frame').width() / 1.792349727);

    jQuery('.views-slideshow-cycle-main-frame').height(ratio);
    jQuery('.views-slideshow-cycle-main-frame').width(width);

    jQuery('.views-slideshow-cycle-main-frame-row').each(function(){
      jQuery(this).height(ratio);
      jQuery(this).width(width);

    });
      
    if($('.agenda-item').length){
      $('.agenda-item article').width($('.view-meeting-details').width() - 50);
    }
  }); 
}(jQuery));

