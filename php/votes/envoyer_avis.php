<html>

<head>
<title>Avis envoy&eacute;</title>
</head>

<body>

<center>
<h1>Votre avis a &eacute;t&eacute; envoy&eacute;</h1>
</center>

<?php	
						  // Récupération des variables
$avis = $_REQUEST['avis'];
echo $avis;
?>

<center>
<form method="post" action="avis.php" name="avis">
   <input type="submit" name="retour" value="Retour">
</form>
</center>

</body>

</html>