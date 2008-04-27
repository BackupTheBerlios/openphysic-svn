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
						  // Récupération des variables
$avis = $_REQUEST['avis'];

//$d = $myEnum["blue"]; 

$avis=2;
echo "Vous avez envoy&eacute; l'avis "."<strong>".$enumAvis[$avis]." (".$avis.")"."</strong>";
?>
</center>

<br/>

<center>
<form method="post" action="avis.php" name="avis">
   <input type="submit" name="retour" value="Retour">
</form>
</center>

</body>

</html>
