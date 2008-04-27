<?php

require('config.php');

**
 * Définition de la classe Vote
 */
class Vote {
  // Déclare un contructeur public
  public function __construct() {
    nouveau();
  }


  public function nouveau() {
    global $resultats;
    //echo "Lancement d'un nouveau vote";
    for ($i=0 ; $i<sizeof($enumAvis) ; $i++) {
      $resultats[$i]="ttt";
    }
  }


}

?>
