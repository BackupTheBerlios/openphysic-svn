<?php

//if (preg_match("** Votre REGEX **", "Ce dans quoi vous faites la recherche"))

//$regex="#guitare#";
//$str="J'aime jouer de la guitare.";
//VRAI

//$regex="#===== .* =====#"; // match avec 5 mais aussi 6 !
$regex="#={5}[ ]*(.*)={5}#"; // match avec 5 mais aussi 6 !
$replace="<h3>$1</h3>";
//$str="===== A2c4 4 =====";
// heredoc string
$str = <<<EOF
xsxdb
=====Xx=====
===== Xx=====
=====Xx =====
===== Xx =====
=====  Xx  =====
TGhgg
EOF;

if (preg_match($regex, $str))
{
	echo "VRAI"."\n";// : $str et $regex matchent";
	//echo 'Le mot que vous cherchez se trouve dans la chaîne';
}
else
{
	echo "FAUX"."\n";
	//echo 'Le mot que vous cherchez ne se trouve pas dans la chaîne';
}

echo "<br/>"."\n";

$new_str = preg_replace($regex,$replace,$str);
echo $new_str;

?>
