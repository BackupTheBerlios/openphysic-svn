<html>

<head>
<title>Avis envoy&eacute;</title>
<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>

<h1>Votre avis a &eacute;t&eacute; envoy&eacute;</h1>

<center>
<?php	

require('config.php');


if (!empty($_POST)) {
    echo '<p>Le bouton enfoncé est le bouton ';
    if (isset($_POST['bouton2'])) {
        echo '2';
    } elseif (isset($_POST['bouton3'])) {
        echo '3';
    } else {
        // par défaut, c'est le bouton 1, même si on ne clique pas/
        echo '1';
    }
    echo '</p>';
    echo '<p>Le champ texte contient : ', $_POST['champ'], '</p>';
}

// Récupération des variables
$avis = $_REQUEST['avis'];

$avis=2;
echo "Vous avez envoy&eacute; l'avis "."<strong>".$enumAvis[$avis]." (".$avis.")"."</strong>";

?>


</center>

<br/>

<center>
<input type="button" name="retour" value="Retour" onclick="self.location.href='avis.php'" onclick> 
</center>


</body>

</html>
