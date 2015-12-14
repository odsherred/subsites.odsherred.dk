<div class="panel-display container-9 panel-node clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel grid-9 alpha omega panel-region-lead">
    <div class="inside"><?php print $content['lead']; ?></div>
  </div>

  <div class="panel-panel grid-9 alpha omega panel-region-middle-top">
    <div class="inside"><?php print $content['middle_top']; ?></div>
  </div>

  <div class="panel-panel grid-6 alpha panel-region-middle-center">
    <div class="inside"><?php print $content['middle_center']; ?></div>
  </div>

  <div class="panel-panel grid-3 omega panel-region-middle-right">
    <div class="inside"><?php print $content['middle_right']; ?></div>
  </div>
</div>
