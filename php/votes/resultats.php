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
require_once('config.php');

$votes->afficher_resultats();


//date_default_timezone_set('UTC');
//echo date('l jS \of F Y h:i:s A');




if (!empty($_POST)) {
  if (isset($_POST['nouveau'])) {
    echo "nouveau vote";
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
