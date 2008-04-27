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


require_once('config.php');

if (!empty($_POST)) {
  //echo '<p>Le bouton enfoncé est le bouton ';
  for ($i=0 ; $i<sizeof($enumAvis) ; $i++) {
    if (isset($_POST['bouton'."$i"])) {
        //echo "$i";
	$avis = $i;
    }
  }
  //echo '</p>';
}

echo "Vous avez envoy&eacute; l'avis "."<strong>".$enumAvis[$avis]." (".$avis.")"."</strong>";

//$resultats[$avis]++;


?>


</center>

<br/>

<center>
<input type="button" name="retour" value="Retour" onclick="self.location.href='avis.php'" onclick> 
</center>


</body>

</html>
