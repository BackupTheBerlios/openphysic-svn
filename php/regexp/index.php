<?php

//if (preg_match("** Votre REGEX **", "Ce dans quoi vous faites la recherche"))

//$regex="#guitare#";
//$str="J'aime jouer de la guitare.";
//VRAI

$regex="#===== .* =====#";
//$str="===== A2c4 4 =====";
// heredoc string
$str = <<<EOF
xsxdb
===== A2c4 4 =====
TGhgg
EOF;

if (preg_match($regex, $str))
{
	echo 'VRAI';
	//echo 'Le mot que vous cherchez se trouve dans la chaîne';
}
else
{
	echo 'FAUX';
	//echo 'Le mot que vous cherchez ne se trouve pas dans la chaîne';
}

?>
