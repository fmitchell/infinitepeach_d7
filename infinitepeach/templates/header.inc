<?php

/**
 * @file
 * Header template html
 */

function infinitepeach_header_common($title, $css) {
	$output = <<< EOD
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd" >
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:csi="http://www.massimocorner.com/libraries/csi/" lang="de">
<head>

<meta charset="utf-8">

<!--Prevent pinch to zoom on iOS devices-->
<meta name="viewport" content="width=device-width; initial-scale=1.0; maximum-scale=1.0; user-scalable=no;" />

<!--Allow saving as a web app on the home screen on iOS Devices (doesn't apply in Baker)-->
<meta name="apple-mobile-web-app-capable" content="yes" />

<!--If the page is saved as a web app, the statusbar will be black-translucent (doesn't apply in Baker)-->
<meta name="apple-mobile-web-app-status-bar-style" content="black-translucent" />

<!--Prevent phone number detection on iOS devices-->
<meta name="format-detection" content="telephone=no" />


<!--Title. The content of the title is displayed on the loading screen on iOS devices-->
<title>$title</title>

<!--Loading the main style sheet-->
<link href="styles/styles.css" rel="stylesheet" type="text/css" />

<!--Loading the dossier specific css-->
<link href="styles/dossiers/$css.css" rel="stylesheet" type="text/css" />

<script src="js/Hyphenator.js" type="text/javascript"></script>
<script src="js/jquery-1.5.min.js" type="text/javascript"></script>
<script type="text/javascript" src="js/tmt_core.js"></script>
<script type="text/javascript" src="js/tmt_net.js"></script>
<script type="text/javascript" src="js/tmt_csi.js"></script>
<script type="text/javascript" src="js/article-nav.js"></script>

<!--Mandatory JavaScripts (Uncomment if not used to speed up performance)
<script type="text/javascript" src="js/jquery.jplayer.min.js"></script>
<script src="js/jquery.touchSwipe-1.2.1.js" type="text/javascript"></script>
-->

</head>
EOD;

	return $output;
}