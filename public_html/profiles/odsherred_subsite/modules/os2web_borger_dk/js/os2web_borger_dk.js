/**
 * @file os2web_borger_dk.js
 */

(function($) {
  Drupal.behaviors.os2web_borger_dk = {
    attach: function(context) {
      $("div.mArticle").hide();
    // borger.dk articles
      $(".microArticle a.gplus").click(function() {
        var article = $(this).parent().find('h2');
        var myid = article.attr('id');
        var style = $('div.' + myid).css('display');
        var path = $(this).css("background-image");
        if (style == 'none') {
          $("div." + myid).show("500");
          $(this).addClass('gminus');
          $(this).removeClass('gplus');
        }
        else {
          $("div." + myid).hide("500");
          $(this).addClass('gplus');
          $(this).removeClass('gminus');
        }
        return false;
      });
      $(".gplus_all").click(function() {
        $("div.mArticle").show();
        $(".microArticle a.gplus").addClass('gminus');
        $(".microArticle a.gplus").removeClass('gplus');
        return false;
      });

      $(".gminus_all").click(function() {
        $(".microArticle a.gminus").addClass('gplus');
        $(".microArticle a.gminus").removeClass('gminus');
        $("div.mArticle").hide();
        return false;
      });
      $(".microArticle h2.mArticle").click(function() {
        var myid = $(this).attr('id');
        var style = $('div.' + myid).css('display');
        var path = $(this).css("background-image");
        if (style == 'none') {
          $("div." + myid).show("500");
          var alink = $(this).parent().find("a.gplus");
          alink.addClass('gminus');
          alink.removeClass('gplus');
        }
        else {
          $("div." + myid).hide("500");
          var alink = $(this).parent().find("a.gminus");
          alink.addClass('gplus');
          alink.removeClass('gminus');
        }
      });
    }
  }
})(jQuery);
