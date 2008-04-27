<?php

//require_once('config.php');

/**
 * Définition de la classe Vote
 */
class Vote {
  public $choix = array('Abstention','D&eacute;favorable','R&eacute;serv&eacute;','Assez favorable','Favorable','Tr&egrave;s favorable');
  public $resultats; // liste comportant les résultats d'un vote
  public $nb_choix; // nb de choix ( = sizeof($choix) )

  private $nb_votes; // nb de votes (y compris les abstentions/nuls explicites)
  private $nb_votants; // nb de votants
  // le nb d'absentions réel est le nb d'absentions explicites + nb_votants-nb_votes

  public function nouveau() {
    $this->nb_choix = sizeof($this->choix);
    for ($i=0 ; $i<$this->nb_choix ; $i++) {
      $this->resultats[$i]=0;
    }
  }

  public function voter($avis) {
    $this->resultats[$avis]++;
    $this->nb_votes++;
  }

  private function moyenne() {
    $somme = 0;
    $nb = 0;
    for ($i=1 ; $i<$this->nb_choix ; $i++) { // $i=1 car on ne compte pas les absentions
      $somme = $somme + $this->resultats[$i]*$i;
      $nb = $nb + $this->resultats[$i];
    }
    if ($nb<>0) {
      return $somme/$nb;
    } else {
      return 0;
    }
  }

  private function moyenne_arrondie() {
    return round($this->moyenne());
  }

  private function choix_moyen() {
    return $this->choix[round($this->moyenne())];
  }

  private function afficher_resultats_table() {
    print '<table border="1">'."\r\n";
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

    print "Moyenne : ".$this->moyenne()."\r\n";
    print "Moyenne arrondie : ".$this->moyenne_arrondie()."\r\n";
    print "Avis moyen : ".$this->choix_moyen()."\r\n";
  }

  private function afficher_resultats_graph() {
    /* Graphique avec JP-Graph */
    /* Requiert GD2 */
    /* JpGraph Error Your PHP installation does not seem to have the required GD 2.x library enabled. Please see the PHP documentation, "Image" section. Make sure that "php_gd2.dll" statement is uncomment in the [modules] section in the php.ini file. */

    print "graph";
  }

  public function afficher_resultats() {
    print "<br/>"."\r\n";
    print "<center>"."\r\n";
    $this->afficher_resultats_table();
    print "<br/><br/>"."\r\n";
    $this->afficher_resultats_graph();
    print "</center>"."\r\n";
  }

  // Déclare un contructeur public
  public function __construct() {
    $this->nouveau();
  }

}

?>
