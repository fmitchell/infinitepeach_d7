<?php

/**
 * @file
 * Navigation template html
 */

function infinitepeach_navigation_common($cur, $prev, $next) {
	$prev = ($prev) ? '<a href="' . $prev . '.html" class="nav-button prev">
	<div class="nav-button-text">Previous Dossier</div>
</a>' : NULL;
	$next = ($next) ? '<a href="' . $next . '.html" class="nav-button next">
	<div class="nav-button-text">Next Dossier</div>
</a>' : NULL;
	$output = <<<EOD
	<!--
############################################################################
"Table of content" in navigation bar #######################################
############################################################################
-->

<div class="nav-bar">
	<div class="nav-bar-container">

        <a href="#navigation" class="nav-button toc"><div class="toc-label">Navigation</div>

        <div class="toc-list">
			<!--Include "Table of content" from external file-->
			<div id="includeTOC" csi:src="inc/toc.html"></div>
		</div><!--Div toc-list-->
		</a>

	</div><!--Div nav-bar-container-->
</div><!--Div nav-bar-->

<!--
############################################################################
End "Table of content" in navigation bar ###################################
############################################################################
-->


<!--
############################################################################
Start dossier navigation in navigation bar #################################
############################################################################
-->

<!--Include the small logo and the cover link-->
<div id="includeLogoAndCoverlink" csi:src="inc/logo-coverlink.html"></div>

$next

$prev

<!--Implementing the Dossier-Number-->
<div id="dossier-number" class="dossier-number"><p>$cur</p></div>

<!--Navigation bar edges-->
<div class="edge-left"></div>
<div class="edge-right"></div>

<!--
############################################################################
End dossier navigation in navigation bar ###################################
############################################################################
-->
EOD;
}