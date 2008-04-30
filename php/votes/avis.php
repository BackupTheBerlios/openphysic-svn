<?php header('Content-type: text/html; charset=UTF-8'); ?> 
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
    print "<input type=\"submit\" name=\"bouton$i\" value=\"".htmlentities($votes->choix[$i])."\" />"."&nbsp;"."\r\n";
  }
  print '</form>'."\r\n";
  print '</center>'."\r\n";

  $votes->voter(0);
  $votes->voter(1);
  $votes->voter(2);
  $votes->voter(3);
  $votes->voter(3);  $votes->voter(3);  $votes->voter(3);  $votes->voter(3);
  $votes->voter(3);
  $votes->voter(4);


  $votes->afficher_resultats();
  //global $ser_votes;
  //$ser_votes = serialize($votes); 

?>

   
</body>
   
</html>
