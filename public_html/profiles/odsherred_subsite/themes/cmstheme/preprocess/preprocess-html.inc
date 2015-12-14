<?php 

function cmstheme_alpha_preprocess_html(&$vars) {
  // Setup IE meta tag to force IE rendering mode
	$meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' =>  'IE=8,IE=Edge,chrome=1',
    ),
    '#weight' => '-99999',
  );
  
  // Add header meta tag for IE to head
  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');


  // Adding new version og jquery to exist alongside the other
  $inline_script = <<<EOL
  <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
  <script type="text/javascript">
    var \$j = jQuery.noConflict(true);
  </script>  
EOL;

  $script_new_jquery = array (
    '#type' => 'markup',
    '#markup' => $inline_script,
  );
  drupal_add_html_head($script_new_jquery, 'jquery-tmpl');

}


?>
