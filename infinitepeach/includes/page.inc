<?php

/**
 * @file
 * Create individual book pieces
 */

function infinitepeach_create_page($node) {
	$title = $node->title;
	$images = field_get_items('node', $node, 'field_image');
	$count = 1;
	$total = count($images);

	//create page for each image
	foreach ($images as $image) {
		$cur = infinitepeach_format_number($count);
		$prev = ($count != 1) ? infinitepeach_format_number($count-=1) : FALSE;
		$next = ($count != $total) ? infinitepeach_format_number($count+=1) : FALSE;

		$html = infinitepeach_get_header($node->title, $cur, TRUE);
		$html .= '<body>' . infinitepeach_get_navigation($cur, $prev, $next);
		$column_img = image_style_path('column', $image['uri']);
		$html .= infinitepeach_page_body($cur, $image['uri'], $column_img);
		$html_file = file_unmanaged_save_data($html, 'public://book/' . $cur . '.html', FILE_EXISTS_REPLACE);

		//page css (styles/dossiers/$cur.css)
		$css = infinitepeach_page_css(file_uri_target($image['uri']));
		$css_file = file_unmanaged_save_data($css, 'public://book/styles/dossiers/' . $cur . '.css', FILE_EXISTS_REPLACE);

		//page image (images/$cur/$image)
		file_unmanaged_copy($image['uri'], 'public://book/images/dossier-' . $cur . '/', FILE_EXISTS_REPLACE);

		//$cur image thumbnail (images/dossier-$cur/thumb/$image_thumb)
		$page_thumb = image_style_path('thumbnail', $image['uri']);
		$thumb_directory = 'public://book/images/dossier-' . $cur . '/thumb';
		file_prepare_directory($thumb_directory, FILE_CREATE_DIRECTORY);
		file_unmanaged_copy($page_thumb, 'public://book/images/dossier-' . $cur . '/thumb', FILE_EXISTS_REPLACE);
		$count++;
	}
}

function infinitepeach_format_number($num) {
	return sprintf("%02d", $num);
}

function infinitepeach_page_body($cur, $img_path, $column_img_path) {
	$output = <<<EOD

<!--Dossier start image-->
<div class="dossier-start-bg">
<!--(if you want to place something on top of the picture, place it here-->
</div><!-- Div dossier-start-bg-->

<!--Arrow which indicates the start of the text-->
<div class="dossier-headline-arrow"><img src="images/dossier-headline-arrow.png" /></div>

<!--"content-element" ensures, that content is placed within the right margins-->
<div class="content-element">
        <!--Starting Headline-->
        <div class="starting-headline">
              <h1>This is built with <em>Laker</em> Ð <br />  A compendium for building digital magazines with HTML5</h1>
        </div><!--Div starting headline-->
</div><!--Div content element-->

<!--Main content-->

<!--"content-element" ensures, that content is placed within the right margins-->
<div class="content-element">


<div class="large-column float-left">
<p><em>Laker</em> is built on top of the <a href="http://www.bakerframework.com" target="_blank">Baker ebook Framework</a> and the <a href="http://www.lessframework.com" target="_blank">LESS CSS Framework</a>. Basically it's a set of files, styles, tips and tricks for building digital publications with HTML5.</p>

<p>This publication demonstrates the main features of <em>Laker</em>. Take a look at the code and the documentation on <a href="http://www.lakercompendium.com" target="_blank">www.lakercompendium.com</a> to see how it's done. It's not that hard! ;) <br />
</p>
<hr /><br /></p>
</div><!--Div large-column float-left-->



<div class="large-column float-left">
<h1>Images &amp; slideshow</h1>
      <h2>Image in text (right)</h2>
      <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas velit tortor, ullamcorper id laoreet vel, ultricies ut lorem. Curabitur porta orci ut lacus vestibulum porttitor. Suspendisse potenti. Donec sodales ante eu dui molestie euismod ultricies nisl sollicitudin. Phasellus eget mauris eu velit mollis consectetur a in elit. Pellentesque eu lorem nunc. Integer eu elit massa. Morbi vestibulum lacus a quam sagittis pulvinar tristique arcu posuere. Aliquam sollicitudin risus risus, at semper neque. Aliquam rhoncus rhoncus ultrices.</p>

      <div class="media-right">
      <img src="images/dossier-$cur/$column_img_path" /></div>

      <p> Aliquam erat volutpat. Aenean in nibh vitae leo placerat viverra. Pellentesque non sapien ac orci fermentum molestie in vitae purus. Cras lacinia turpis nec orci blandit adipiscing. Morbi tempor commodo leo, quis scelerisque risus pretium quis. Cras suscipit magna eget tortor sagittis fringilla. Praesent arcu justo, ultrices eu interdum nec, ornare aliquam urna. Vivamus cursus posuere erat id faucibus.</p>
      <p>Morbi semper ultrices porta. Aenean dignissim, sapien eget sodales mollis, massa urna malesuada elit, sit amet vulputate justo augue in massa. Praesent mattis accumsan blandit. Mauris nec enim ante. Sed fringilla interdum eros, nec lacinia turpis iaculis vel. Vestibulum leo ipsum, consequat a dignissim sit amet, egestas in urna. Donec nisl velit, pulvinar id ullamcorper vitae, imperdiet et leo. Donec ultricies cursus varius. Pellentesque elit arcu, pulvinar in fermentum non, faucibus eu quam. Suspendisse mollis aliquam sagittis. Vestibulum pellentesque accumsan arcu, vitae mattis tellus luctus id. Vivamus sed condimentum leo.</p>
</div><!--Div large-column float-left-->


  <div class="large-column float-right">
      <h2>Image in text (left)</h2>
      <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas velit tortor, ullamcorper id laoreet vel, ultricies ut lorem. Curabitur porta orci ut lacus vestibulum porttitor. Suspendisse potenti. Donec sodales ante eu dui molestie euismod ultricies nisl sollicitudin. Phasellus eget mauris eu velit mollis consectetur a in elit. Pellentesque eu lorem nunc. Integer eu elit massa. Morbi vestibulum lacus a quam sagittis pulvinar tristique arcu posuere. Aliquam sollicitudin risus risus, at semper neque. Aliquam rhoncus rhoncus ultrices.</p>

      <div class="media-left">
      <img src="images/dossier-$cur/$column_img_path" /></div>

      <p> Aliquam erat volutpat. Aenean in nibh vitae leo placerat viverra. Pellentesque non sapien ac orci fermentum molestie in vitae purus. Cras lacinia turpis nec orci blandit adipiscing. Morbi tempor commodo leo, quis scelerisque risus pretium quis. Cras suscipit magna eget tortor sagittis fringilla. Praesent arcu justo, ultrices eu interdum nec, ornare aliquam urna. Vivamus cursus posuere erat id faucibus.</p>
      <p>Morbi semper ultrices porta. Aenean dignissim, sapien eget sodales mollis, massa urna malesuada elit, sit amet vulputate justo augue in massa. Praesent mattis accumsan blandit. Mauris nec enim ante. Sed fringilla interdum eros, nec lacinia turpis iaculis vel. Vestibulum leo ipsum, consequat a dignissim sit amet, egestas in urna. Donec nisl velit, pulvinar id ullamcorper vitae, imperdiet et leo. Donec ultricies cursus varius. Pellentesque elit arcu, pulvinar in fermentum non, faucibus eu quam. Suspendisse mollis aliquam sagittis. Vestibulum pellentesque accumsan arcu, vitae mattis tellus luctus id. Vivamus sed condimentum leo.</p>
</div><!--Div large-column float-right-->

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

function infinitepeach_page_css($cur, $img_path) {
	$output = <<<EOD

.dossier-start-bg {
	background-image:url(../../images/dossier-$cur/$img_path);
	}

@media only screen and (min-width: 768px) and (max-width: 991px) {
}

@media only screen and (min-device-width: 481px) and (max-device-width: 1024px) and (orientation:portrait) {
}

@media only screen and (max-device-width: 1024px) and (orientation:landscape) {
}

@media only screen and (max-width: 767px) {
}

@media only screen and (min-width: 480px) and (max-width: 767px) {
}

@media
	only screen and (-webkit-min-device-pixel-ratio: 2),
	only screen and (min-device-pixel-ratio: 2) {
}
EOD;
	return $output;
}