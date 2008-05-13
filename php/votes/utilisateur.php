<?php
class utilisateur {
  public $id;
  public $nom;
  public $prenom;
  public $login;
  public $password;
  public $is_admin = false;

  function __construct() {
    //echo "construct";
  }

  function update_from_db($result) {
    extract($result);
    //echo $result;
    $this->id=$id;
    $this->nom=$nom;
    $this->prenom=$prenom;
  }
}

//$u1 = new utilisateur();
?>
