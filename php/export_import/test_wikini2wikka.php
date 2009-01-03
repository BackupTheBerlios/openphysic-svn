<?php

include_once("wikini2wikka.php");

$txt_from = <<<EOF
====== Titre ======
[[http://www.monsite.com/image.png image]]
texte
EOF;

$trans = new wikini2wikka();
$txt_to=$trans->execute($txt_from);

echo $txt_to;
?>