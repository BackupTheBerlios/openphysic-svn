<?php

//require_once('config.php');

/**
 * Définition de la classe Vote
 */
class Vote {
  public function nouveau() {
    global $resultats;
    //echo "Lancement d'un nouveau vote";
    for ($i=0 ; $i<sizeof($enumAvis) ; $i++) {
      $resultats[$i]="ttt";
    }
  }

  public function afficher_resultats() {
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
  }

  // Déclare un contructeur public
  public function __construct() {
    //nouveau();
  }

}

?>
