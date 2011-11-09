<?php

/**
 * @file
 * Create cover piece
 */

function infinitepeach_create_cover($node) {
	$title = $node->title;
	$cover_img = field_get_items('node', $node, 'field_cover_img');

	//cover html (001.html)
	$html = infinitepeach_get_header($node->title, 'cover');
	$html .= infinitepeach_cover_body($cover_img);
	$html_file = file_unmanaged_save_data($html, 'public://001.html', FILE_EXISTS_REPLACE);

	//cover css (styles/dossiers/cover.css)

	//cover image (images/cover/$image)

	//cover image thumbnail (images/cover/$image_thumb)
}

function infinitepeach_cover_body($cover_img_path) {
	$output = <<<EOD
<body>

<!--Enable text hyphenation with Hyphenator.js-->
<div class="hyphenate">

<!--Dossier start image-->
<div class="dossier-start-bg">
<!--(if you want to place something on top of the picture, place it here-->

<a href="01.html"><img src="$cover_img_path" /></a>

</div><!-- Div dossier-start-bg-->

</div><!--Div hyphenate-->

<!--Include footer data from inc/footer.html-->
<div class="footer">
  <div id="includeFooter" csi:src="inc/footer.html"></div>
</div><!--Div footer-->

</body>
</html>
EOD;
	return $output;
}