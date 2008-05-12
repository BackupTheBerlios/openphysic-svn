<?php
/* Login */
//session_start();// on démarre une session

//connexion à la base de données
require_once("connect.php");

/* Utilisateur existant - mot de passe Ok */
//$login='scelles';
//$password='0000';

/* Utilisateur existant - mauvais mot de passe */
//$login='scelles';
//$password='err';

/* Utilisateur inexistant dans la base */
//$login='inconnu';
//$password='inconnu';

/* Utilisateur existant - mot de passe Ok */
//$login='pnom';
//$password='1234';

/* Administrateur - mot de passe Ok */
$login='admin';
$password='7777';

$password_tape = hash($params['hash'],$password);

// hash('md5','0000') = 4a7d1ed414474e4033ac29ccb8653d9b
// hash('md5','1234') = 81dc9bdb52d04dc20036dbd8313ed055
// hash('md5','7777') = d79c8788088c2193f0244d8f1f36d2db

//echo "password=$password";

//lecture du mot de passe dans la base
$query = "SELECT * FROM login WHERE login='$login'";
$query = mysql_query($query) or die(htmlentities('Requête échouée : ') . mysql_error());;
//echo $query;

unset($result);
$result = mysql_fetch_array($query);
if (sizeof($result)>1) {
  extract($result);
} else {
}
$bon_password = $password; //$result['password'];

//echo "bon_password=$bon_password";


if ($password_tape == $bon_password) // Si le mot de passe est valide
{
  //echo "Bon password";
  echo htmlentities("Bienvenue $prenom $nom ($login)")." - ";
  if ($result['is_admin']) {
    echo "Vous etes administrateur";

    $query = "SELECT * FROM login";
    $query = mysql_query($query);

    echo "<br/>\n";

    echo "<table>\n";

    $i=0;
    while ($line = mysql_fetch_array($query)) {
      extract($line);
      echo "<tr><td>$i</td><td>$login</td><td>$nom</td><td>$prenom</td></tr>\n";
      $i++;
    }

    echo "</table>\n";


  } else {
    echo "Vous êtes simple votant";
  }
} else {
  //echo "Mauvais mot de passe pour \"$login\" ou utilisateur inconnu";
  
  // compter le nb d'utilisateurs (0 ou 1) ayant ce login
  if (sizeof($result)>1) {
    echo htmlentities("Mauvais mot de passe pour \"$login\"");
  } else {
    echo htmlentities("Utilisateur \"$login\" inconnu");
  }
}


// Printing results in HTML
/*
echo "<table>\n";
while ($line = mysql_fetch_array($query, MYSQL_ASSOC)) {
    echo "\t<tr>\n";
    foreach ($line as $col_value) {
        echo "\t\t<td>$col_value</td>\n";
    }
    echo "\t</tr>\n";
}
echo "</table>\n";
*/

// Free resultset
//mysql_free_result($query); // $result

// Closing connection
mysql_close($db);

?>
