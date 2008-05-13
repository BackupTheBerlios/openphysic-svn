<?php

if (!defined('VOTES_VERSION'))
{
	die ("acc&egrave;s direct interdit");
}

$query = "SELECT * FROM login";
$query = mysql_query($query);

echo "<center>\n";

echo "<table border>\n";

$i=0;
while ($line = mysql_fetch_array($query)) {
  extract($line);
  echo "<tr><td>$i</td><td>$login</td><td>$nom</td><td>$prenom</td></tr>\n";
  $i++;
}

echo "</table>\n";

echo "</center>\n";

?>
