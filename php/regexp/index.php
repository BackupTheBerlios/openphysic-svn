<?php

//if (preg_match("** Votre REGEX **", "Ce dans quoi vous faites la recherche"))

//$regex="#guitare#";
//$str="J'aime jouer de la guitare.";
//VRAI

//$regex="#===== .* =====#"; // match avec 5 mais aussi 6 !
$regex="#={5}.*={5}#"; // match avec 5 mais aussi 6 !
//$str="===== A2c4 4 =====";
// heredoc string
$str = <<<EOF
xsxdb
===== Xx =====
TGhgg
EOF;

if (preg_match($regex, $str))
{
	echo "VRAI";// : $str et $regex matchent";
	//echo 'Le mot que vous cherchez se trouve dans la chaîne';
}
else
{
	echo "FAUX";
	//echo 'Le mot que vous cherchez ne se trouve pas dans la chaîne';
}

?>
