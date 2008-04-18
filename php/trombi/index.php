<?php

  /*****************************************************************
   * Script en PHP permettant de générer un trombinoscope          *
   * Technique : ce script est exécuté sur un serveur web (Apache) *
   *  il renvoie une page web qui peut ensuite être visualisée     *
   *  via un navigateur web (Firefox, Internet Explorer...)        *
   *  Les photos doivent être stockées dans un répertoire ./img    *
   *  Les noms/prénoms des personnes sont dans un fichier .csv     *
   *****************************************************************/

  /*****************************************************************
   * Prérequis :                                                   *
   *  Installation d'un serveur web Apache                         *
   *  Copie du répertoire contenant script, images et fichier .csv *
   *    dans /var/www/trombi                                       *
   *  Lancement du navigateur à l'adresse                          *
   *    http://127.0.0.1/trombi/index.php                          *
   *****************************************************************/

  /*****************************************************************
   * ToDo :                                                        *
   *  Utilisation du module Pear php-file pour la lecture de       *
   *    fichiers CSV                                               *
   *    http://pear.php.net/package/File                           *
   *****************************************************************/

  // Const
$liste = "main.csv";
$nb_colonnes = 8;
$titre = "Trombinoscope";

//include ''

// Header

print "<html>
  <head>
    <title>
      $titre
    </title>
    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/>  
  </head>
  <body>
    <center>
      <h1>$titre</h1>
    </center>

    <center>
      <table>
";

// Partie centrale
$indice=0;
$ligne=1;
$colonne=1;

$indice=0;
$file_handle = fopen("main.csv", "r");
while (!feof($file_handle) ) {
  $line_of_text = fgetcsv($file_handle, 1024);

  if ($indice!=0) {
    if ($colonne==1) {
      print "        <tr>"."\r\n";
    }

    /*
     print "          <td>
     X
     </td>
     ";
    */

    $PHOTO='1';
    $NOM=$line_of_text[0];
    $PRENOM=$line_of_text[1];
    $NOM_COURT=$line_of_text[3];
    $PRENOM_COURT=$line_of_text[4];
    if ($NOM_COURT=="") {
      $NOM_COURT=$NOM;
    }
    if ($PRENOM_COURT=="") {
      $PRENOM_COURT=$PRENOM;
    }
    $NOMPRENOM=$NOM_COURT." ".$PRENOM_COURT;

    if ($PHOTO=='') {
      $PHOTO="img/"."nophoto.png";
    } else {
      //try {
      $numphoto=$PHOTO; //int($PHOTO); // ToDo voir conversion string vers integer
      //}
      //catch {
      //$numphoto=null;
      if ($numphoto!=null) {
        $PHOTO=sprintf("img/%06d.jpg",$PHOTO);
      }
    }

    print "          <td>
            <table>
              <tr><td><img src=\"$PHOTO\" align='bottom' alt=\"$NOMPRENOM\"></td></tr>
              <tr><td>$NOM_COURT</td></tr>
              <tr><td>$PRENOM_COURT</td></tr>
           </table>
          </td>
";


    $colonne=$colonne+1; // nouvelle colonne
			
    if ($colonne==$nb_colonnes+1) { // nouvelle ligne
      $colonne=1;
      $ligne=$ligne+1;
    }

    if ($colonne==1) {
      print "        </tr>"."\r\n";
    }
  }

  $indice=$indice+1;
 }


// Fin du fichier html
print "      </table>
    </center>
  </body>
</html>
";

// Fermeture du fichier csv
fclose($file_handle);
?>

