<div class="panel-display panel-node clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-top-container clearfix">
    <div class="panel-panel grid-4 alpha panel-region-top-left">
      <div class="inside"><?php print $content['top_left']; ?></div>
    </div>

    <div class="panel-panel grid-8 omega panel-region-top-right">
      <div class="inside"><?php print $content['top_right']; ?></div>
    </div>
  </div>

  <div class="panel-panel grid-12 alpha omega panel-region-bottom">
    <div class="inside"><?php print $content['bottom']; ?></div>
  </div>
</div>

