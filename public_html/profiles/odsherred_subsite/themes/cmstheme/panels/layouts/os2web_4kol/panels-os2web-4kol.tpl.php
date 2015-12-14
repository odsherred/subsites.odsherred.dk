<div class="panel-display container-12 panel-node clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="inner-wrapper clearfix">
	  <div class="inner clearfix">
		  <div class="panel-panel grid-3 alpha panel-region-kol1">
		    <div class="inside"><?php print $content['kol1']; ?></div>
		  </div>
		
		  <div class="panel-panel grid-3 panel-region-kol2">
		    <div class="inside"><?php print $content['kol2']; ?></div>
		  </div>
		
		  <div class="panel-panel grid-3 panel-region-kol3">
		    <div class="inside"><?php print $content['kol3']; ?></div>
		  </div>
		
		  <div class="panel-panel grid-3 omega panel-region-kol4">
		    <div class="inside"><?php print $content['kol4']; ?></div>
		  </div>
	  </div>
  </div>
</div>
