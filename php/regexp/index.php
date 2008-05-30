<?php

//if (preg_match("** Votre REGEX **", "Ce dans quoi vous faites la recherche"))
if (preg_match("#guitare#", "J'aime jouer de la guitare."))
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
