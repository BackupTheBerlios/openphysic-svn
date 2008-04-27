<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
    "http://www.w3.org/TR/html4/loose.dtd"> 
<html>

<head>
  <title>R&eacute;sultats du vote</title>
  <link rel="stylesheet" type="text/css" href="style.css" />

  <meta http-equiv="refresh" content="2">

</head>

<body>

<h1>R&eacute;sultats du vote</h1>

<center>
<?php
require('config.php');
global $resultats;

  function nouveau_vote() {
    global $resultats;
    echo "Lancement d'un nouveau vote";
    for ($i=0 ; $i<sizeof($enumAvis) ; $i++) {
      $resultats[$i]="ttt";
    }
  }

//date_default_timezone_set('UTC');
//echo date('l jS \of F Y h:i:s A');

print '<table border="1" align="center">'."\r\n";
print '  <tr>'."\r\n";
for ($i=0 ; $i<sizeof($enumAvis) ; $i++) {
   print "    <th align=\"center\">$enumAvis[$i]</th>"."\r\n";
}
print '  </tr>'."\r\n";
print '  <tr>'."\r\n";
for ($i=0 ; $i<sizeof($enumAvis) ; $i++) {
   print "    <td align=\"center\">$resultats[$i]</td>"."\r\n";
}
print '  </tr>'."\r\n";
print '</table>'."\r\n";


if (!empty($_POST)) {
  if (isset($_POST['nouveau'])) {
    nouveau_vote();
  }
}


?>

<br/>

<form action="<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
<input type="submit" name="nouveau" value="Nouveau vote" />
</form> 


</center>

</body>

</html>
