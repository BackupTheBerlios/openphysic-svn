<?php
$mabase = mysql_connect('localhost', 'USER', 'PASSWORD');
if (!$mabase) {
   die('Impossible de se connecter : ' . mysql_error());
}

$result = mysql_select_db('BASE');
if (!$result) {
   die ('Impossible de s�lectionner la base de donn�es : ' . mysql_error());
}
?>
