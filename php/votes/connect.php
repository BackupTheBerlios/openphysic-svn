<?php
require_once('config.php');

// connexion à la base (localhost user password)
//$db = mysql_connect($params['dbadr'], $params['dbuser'], $params['dbpwd']) or die('Impossible de se connecter : ' . mysql_error());
//echo 'Connecté à la base';

// choix de la base (qui contient les différentes tables)
//$result = mysql_select_db($params['dbname']) or die ('Impossible de sélectionner la base de données : ' . mysql_error());

try
{
        $connexion = new PDO('mysql:host='.$params['dbadr'].';dbname='.$params['dbname'], $params['dbuser'], $params['dbpwd']);
	//echo "Connection Ok";
}
 
catch(Exception $e)
{
        echo 'Erreur : '.$e->getMessage().'<br />';
        echo 'N° : '.$e->getCode();
}
?>
