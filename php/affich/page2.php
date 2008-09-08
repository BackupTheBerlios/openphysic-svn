<html>
  <head>
    <title>Title</title>
  </head>
  <body>
    <h1>Page 2</h1>
<?php
echo print_r($_GET);

  if ($param1==1) {
echo "OK !!";
  } else {
echo "Erreur param1 $param1 n'est pas passé<br>\n";
  }
?>
  </body>
</html>
