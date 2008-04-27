<html>
<head>
<title>Avis</title>
<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>

<h1>Avis</h1>

<?php
   require('config.php');
?>

<center>
<form method="post" action="envoyer_avis.php" name="avis">
   <input type="submit" name="avis4" value="Tr&egrave;s favorable">
   <input type="submit" name="avis3" value="Favorable">
   <input type="submit" name="avis2" value="Assez favorable">
   <input type="submit" name="avis1" value="R&eacute;serv&eacute;">
   <input type="submit" name="avis0" value="D&eacute;favorable">
</form>
</center>
   
</body>
   
</html>
