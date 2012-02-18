<?php

/**
 * @file
 * Create table of contents piece
 */

function infinitepeach_create_toc($node, $book_directory) {
	$title = $node->title;
	$images = field_get_items('node', $node, 'field_image');
	$count = 1;
	$toc_entries = array();

	//create toc entry for each image
	foreach ($images as $key => $image) {
		//setup cover
		if ($key < 1) {
			$dossier = '001';
			$number = 'C';
			$thumb = 'cover/thumb/' . file_uri_target($image['uri']);
			$label = 'Cover';
			$title = 'Issue #1';
		}
		else {
			$cur = infinitepeach_format_number($count);
			$dossier = $cur;
			$number = $count;
			$thumb = 'dossier-' . $cur . '/thumb/' . file_uri_target($image['uri']);
			$label = 'Dossier #' . $count;
			$title = 'Title #' . $count;
			$count++;
		}
		$toc_entries[] = infinitepeach_toc_entry($dossier, $number, $thumb, $label, $title);
	}

	$html = infinitepeach_toc_body(implode('/n', $toc_entries));
	$html_file = file_unmanaged_save_data($html, $book_directory . '/inc/toc.html', FILE_EXISTS_REPLACE);

}

function infinitepeach_toc_entry($dossier, $number, $thumb, $label, $title) {
	$output = <<<EOD
<a class="toc-dossier" href="$dossier.html">
<div class="toc-dossier-number">$number</div>
<img class="toc-thumb" src="images/$thumb" />
<h1>$label</h1>
<p>$title</p>
</a><!--Link toc-dossier-->
EOD;
	return $output;
}

function infinitepeach_toc_body($entries) {
	$output = <<<EOD
<div class="hyphenate">

$entries

</div><!--Div Hyphenate-->
EOD;
	return $output;
}