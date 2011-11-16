<?php

/**
 * @file
 * Create cover piece
 */

function infinitepeach_create_cover($node) {
	$title = $node->title;
	$cover_img = field_get_items('node', $node, 'field_image');

	//cover html (001.html)
	$html = infinitepeach_get_header($node->title, 'cover', FALSE);
	$html .= infinitepeach_cover_body();
	$html_file = file_unmanaged_save_data($html, 'public://book/001.html', FILE_EXISTS_REPLACE);

	$image_directory = 'public://book/images/cover';

	//create image derivatives
	$derivatives = array(
		'page' => '',
		'toc_thumb' => '/thumb',
	);
	foreach ($derivatives as $style => $derivative) {
		$directory = $image_directory . $derivative;
		file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
		$style = image_style_load($style);
		$creation = image_style_create_derivative($style, $cover_img[0]['uri'], $directory . '/' . file_uri_target($cover_img[0]['uri']));
	}

	//cover css (styles/dossiers/cover.css)
	$css = infinitepeach_cover_css(file_uri_target($cover_img[0]['uri']));
	$css_file = file_unmanaged_save_data($css, 'public://book/styles/dossiers/cover.css', FILE_EXISTS_REPLACE);
}

function infinitepeach_cover_body() {
	$output = <<<EOD
<body>

<!--Enable text hyphenation with Hyphenator.js-->
<div class="hyphenate">

<!--Dossier start image-->
<div class="dossier-start-bg">
<!--(if you want to place something on top of the picture, place it here-->

<a href="01.html"><img src="images/cover/cover-typo.png" /></a>

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

function infinitepeach_cover_css($cover_img_path) {
	$output = <<<EOD
body {
	background-color:#000;
	}
.content-element a {
	color:#fff;
	}
.dossier-start-bg {
	background-image:url(../../images/cover/$cover_img_path);
	text-align:center;
	}
.dossier-start-bg img {
	margin-top:100px;
	}
@media only screen and (min-width: 768px) and (max-width: 991px) {
}
@media only screen and (min-device-width: 481px) and (max-device-width: 1024px) and (orientation:portrait) {
	}
@media only screen and (max-device-width: 1024px) and (orientation:landscape) {
	}
@media only screen and (max-width: 767px) {
	.dossier-start-bg img {
	width:90%;
	height:auto;
	}
}
@media only screen and (min-width: 480px) and (max-width: 767px) {
.dossier-start-bg img {
	width:90%;
	height:auto;
	margin-top:0px;
	}
}
@media
	only screen and (-webkit-min-device-pixel-ratio: 2),
	only screen and (min-device-pixel-ratio: 2) {
}
EOD;
	return $output;
}