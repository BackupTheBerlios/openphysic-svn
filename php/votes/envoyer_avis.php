<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
    "http://www.w3.org/TR/html4/loose.dtd"> 
<html>

<head>
<title>Avis envoy&eacute;</title>
<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>

<h1>Votre avis a &eacute;t&eacute; envoy&eacute;</h1>

<center>

<?php	



global $votes;



if (!empty($_POST)) {
  for ($i=0 ; $i<6 ; $i++) {
    if (isset($_POST['bouton'."$i"])) {
        echo "Le bouton enfonc&eacute; est le bouton $i"."\r\n";
	$avis = $i;
	break;
    }
  }
}

echo "<br/>"."\r\n";

echo "Vous avez envoy&eacute; l'avis "."<strong>".$votes[$avis]." (".$avis.")"."</strong>";

//$votes->voter($avis);


$votes->afficher_resultats();


?>


</center>

<br/>

<center>
<input type="button" name="retour" value="Retour" onclick="self.location.href='avis.php'" onclick> 
</center>


</body>

</html>
