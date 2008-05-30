<?php

define("IMPORT_EXPORT_VERSION", "0.0.1");

// RegExp PHP POSIX egreg...
// PCRE - Perl Compatible Regular Expressions (preg...)
//import pcre; 

include_once("connect.php");
include_once("exception.php");
include_once("translator.php");

// Parameters
$params_from = array (
  'dbtype'=>'mysql',       // type de base de données (mysql, posgresql, sqlite...) et
  'dbadr'=>'localhost',    // adresse de la base de données
  'dbuser'=>'scls',        // nom d'utilisateur de la base de données
  'dbpwd'=>'0000',         // mot de passe de l'utilisateur de la base de données
  'dbname'=>'celles',       // nom de la base de données
  'tableprefix'=>'wikini_', // prefixe des tables de la base de données
);

$params_to = array (
  'dbtype'=>'mysql',       // type de base de données (mysql, posgresql, sqlite...) et
  'dbadr'=>'localhost',    // adresse de la base de données
  'dbuser'=>'scls',        // nom d'utilisateur de la base de données
  'dbpwd'=>'0000',         // mot de passe de l'utilisateur de la base de données
  'dbname'=>'celles_bak',       // nom de la base de données
  'tableprefix'=>'wikini_', // prefixe des tables de la base de données
);

echo "<h1>Debut du script</h1>"."\n";


//try {
	$connexion_from=connect($params_from);
//}
//catch (MyException $e) {
//	echo "Erreur de connexion";
//}

	$connexion_to=connect($params_to);


// copie "from" vers "to"

// modification de "to"
//$sql = 'UPDATE `celles_bak`.`wikini_users` SET `name` = \'Test\' WHERE CONVERT(`wikini_users`.`name` USING utf8) = \'ElevE\' LIMIT 1;';
//$sql = 'UPDATE `celles_bak`.`wikini_users` SET `name` = \'Test\' WHERE `wikini_users`.`name` = \'ElevE\';';
//$prep_sql = $connexion_to->prepare($sql);
//$prep_sql->execute();

/*
$resultats=$connexion_to->query("SELECT name FROM wikini_users");
$resultats->setFetchMode(PDO::FETCH_OBJ); // on dit qu'on veut que le résultat soit récupérable sous forme d'objet
while( $ligne = $resultats->fetch() ) // on récupère la liste
{
        echo 'Utilisateur : '.$ligne->name.'<br />'; // on affiche les membres
}
$resultats->closeCursor(); // on ferme le curseur des résultats
*/

$sql = 'SELECT * FROM `wikini_pages` WHERE `tag` LIKE CONVERT(_utf8 \'SharpDevelop\' USING latin1) COLLATE latin1_swedish_ci';
$resultats=$connexion_to->query($sql);
$resultats->setFetchMode(PDO::FETCH_OBJ); // on dit qu'on veut que le résultat soit récupérable sous forme d'objet
$ligne = $resultats->fetch();
$txt_from=$ligne->body;



$txt_from = <<<EOF
xsxdb
=====T5=====
===== T5=====
=====T5 =====
===== T5 =====
=====  T5  =====
==== T4 ====
=== T3 ===
== T2 ==
{{redirect page="Toto"}}
**bold**
//italic//
__underline__
TGhgg
EOF;

/*
//italique//
@@barré@@
##texte à espacement fixe##
*/

$txt_to=$txt_from;
//$txt_to=ereg_replace("=====","!!!!!",$txt_to);
//$txt_to=ereg_replace("===== SharpDevelop =====","<h3>SharpDevelop</h3>",$txt_to);
//$txt_to=ereg_replace("^=====","<h3>",$txt_to);
//$txt_to=ereg_replace("=====$","</h3>",$txt_to);

//$txt_to=ereg_replace("^=====","<h3>",$txt_to); $txt_to=ereg_replace("=====","</h3>",$txt_to);
//$txt_to=ereg_replace("={5}(.*)={5}","<h3>$1</h3>",$txt_to);
//$txt_to=preg_replace('#={5}[ ]*(.*)[ ]*={5}#','<h3>$1</h3>',$txt_to);

$trans = new Translator();
$trans->add('/={5}[ ]*(.*)[ ]*={5}/','<h1>$1</h1>'); // h1
$trans->add('#={4}[ ]*(.*)[ ]*={4}#','<h2>$1</h2>'); // h2
$trans->add('#={3}[ ]*(.*)[ ]*={3}#','<h3>$1</h3>'); // h2
$trans->add('#={2}[ ]*(.*)[ ]*={2}#','<h4>$1</h4>'); // h2
$trans->add('#{{redirect page="(.*)"}}#',"[[REDIRECT->$1]]"); // redirect
$trans->add('#[*]{2}(.*)[*]{2}#','<b>$1</b>'); // bold
$trans->add('#[/]{2}(.*)[/]{2}#','<i>$1</i>'); // italic
$trans->add('#[_]{2}(.*)[_]{2}#','<u>$1</u>'); // underline

//$trans->show();


//$trans->add('#={3}[ ]*(.*)[ ]*={3}#','<h3>$1</h3>');
//$trans->add('#={2}[ ]*(.*)[ ]*={2}#','<h4>$1</h4>');
$txt_to=$trans->execute($txt_from);

/*
echo "<h2>Orginal</h2>"."\n";
echo "<pre>"."\n";
echo "$txt_from"."\n";
echo "</pre>"."\n";

echo "<h2>Modif</h2>"."\n";
echo "<pre>"."\n";
echo "$txt_to"."\n";
echo "</pre>"."\n";
*/

// syntaxe chaine "heredoc"
$str = <<<EOF
<table border width="100%">
  <tr>
    <th width="50%">From</th><th width="50%">To</th>
  </tr>
  <tr valign="top">
    <td>
      <pre>
$txt_from
      </pre>
    </td>
    <td>
      <pre>
$txt_to
    </td>
      </pre>
  </tr>
</table>
EOF;

echo $str."\n";

echo "<h1>Fin du script</h1>"."\n";


// Close connexion
$connexion_from=null;
$connexion_to=null;

?>
