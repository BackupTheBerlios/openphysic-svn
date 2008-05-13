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
}

//$u1 = new utilisateur();
?>
