<?php

//require_once('config.php');

/**
 * Définition de la classe Vote
 */
class Vote {
  public $choix = array('Abstention','D&eacute;favorable','R&eacute;serv&eacute;','Assez favorable','Favorable','Tr&egrave;s favorable');
  public $resultats;
  public $nb_choix;

  public function nouveau() {
    $this->nb_choix = sizeof($this->choix);
    for ($i=0 ; $i<$this->nb_choix ; $i++) {
      $this->resultats[$i]=0;
    }
  }

  public function voter($avis) {
    $this->resultats[$avis]++;
  }

  public function afficher_resultats() {
    print '<table border="1" align="center">'."\r\n";
    print '  <tr>'."\r\n";
    for ($i=0 ; $i<$this->nb_choix ; $i++) {
       print "    <th align=\"center\">".$this->choix[$i]."</th>"."\r\n";
    }
    print '  </tr>'."\r\n";
    print '  <tr>'."\r\n";
    for ($i=0 ; $i<$this->nb_choix ; $i++) {
       print "    <td align=\"center\">".$this->resultats[$i]."</td>"."\r\n";
    }
    print '  </tr>'."\r\n";
    print '</table>'."\r\n";
  }

  // Déclare un contructeur public
  public function __construct() {
    $this->nouveau();
  }

}

?>
