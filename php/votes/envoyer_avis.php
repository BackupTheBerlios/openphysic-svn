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

require('config.php');


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

$resultats[$avis]++;

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

?>


</center>

<br/>

<center>
<input type="button" name="retour" value="Retour" onclick="self.location.href='avis.php'" onclick> 
</center>


</body>

</html>
