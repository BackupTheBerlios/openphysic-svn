<?php
/* 
titre: Action Math pour Wikini
Auteur: Cl�ment Seifert (algebra.com)
Auteur: S�bastien Celles (mimetex)
License: GPL
*/

if (!defined("WIKINI_VERSION"))
 {
         die ("acc�s direct interdit");
 }
 
$expression = $this->GetParameter("expression");
$baseurl = "http://www.algebra.com/cgi-bin/plot-formula.mpl?expression=";
$fullurl = $baseurl . rawurlencode($expression);

echo "<img src=\"$fullurl\" alt=\"expression math\" valign=\"middle\"/>";

?> 