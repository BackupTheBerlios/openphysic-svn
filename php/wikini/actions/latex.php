<?php
/* 
titre: Action LaTeX pour Wikini
Auteur: S�bastien Celles (mimetex)
License: GPL
*/

if (!defined("WIKINI_VERSION"))
 {
         die ("acc�s direct interdit");
 }
 
$expression = $this->GetParameter("expression");
$baseurl = "http://www.forkosh.com/mimetex.cgi?";
$fullurl = $baseurl . rawurlencode($expression);

echo "<img src=\"$fullurl\" alt=\"expression math\" valign=\"middle\"/>";

?> 