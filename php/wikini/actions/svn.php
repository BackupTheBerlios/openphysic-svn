<?php

// protection contre un appel direct
if (!defined("WIKINI_VERSION"))
{
	die ("accès direct interdit");
}

// recuperation des parametres
$mode = $this->GetParameter("mode");
$url = $this->GetParameter("url");


//strWeb = "http://svn.berlios.de/wsvn/openphysic";  // websvn
$strWeb = "http://svn.berlios.de/viewcvs/openphysic"; // viewcvs
$strCheckout = "http://svn.berlios.de/viewcvs/*checkout*/openphysic";
$strAnonymous = "svn checkout svn://svn.berlios.de/openphysic";
$strDevel = "svn checkout svn+ssh://scls19fr@svn.berlios.de/svnroot/repos/openphysic";


if (empty($mode)) {
	$mode = "web"; // parametres par defaut
}




if ( $mode == "web" ) {
	$str = $strWeb;
	echo $str.$url;
}

else if ( $mode == "checkout" ) {
	$str = $strCheckout;
	echo $str.$url;
}

else if ( $mode == "anonymous" ) {
	$str = $strAnonymous;
	echo $str.$url;
}

else if ( $mode == "devel" ) {
	$str = $strDevel;
	echo $str.$url;
}

else if ( $mode == "getsource" ) {
echo '<h4> Obtenir le code source </h4>';
echo '<h5> Accès web </h5>';
echo '<a href="'.$strWeb.$url.'">'.$strWeb.$url.'</a><br />';
echo '<br />';
echo '<h5> Accès anonyme </h5>';
echo '<tt>'.$strAnonymous.$url.'</tt><br />';
echo '<br />';
echo '<h5> Accès développeur </h5>';
echo '<tt>'.$strDevel.$url.'</tt>';
}

else {
	$str = $strWeb;
}

/*
if (!empty($url)) {
	$str = $str.$url;
}
*/


?>