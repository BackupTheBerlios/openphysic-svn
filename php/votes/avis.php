<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
    "http://www.w3.org/TR/html4/loose.dtd"> 
<html>
<head>
<title>Avis</title>
<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>

<h1>Avis</h1>

<?php
  require_once('config.php');

  print '<center>'."\r\n";
  print '<form method="post" action="envoyer_avis.php" name="avis">'."\r\n";

  for ($i=0 ; $i<$votes->nb_choix ; $i++) {
    print "<input type=\"submit\" name=\"bouton$i\" value=\"".$votes->choix[$i]."\" />"."&nbsp;"."\r\n";
  }
  print '</form>'."\r\n";
  print '</center>'."\r\n";

  $votes->afficher_resultats();

?>

   
</body>
   
</html>
