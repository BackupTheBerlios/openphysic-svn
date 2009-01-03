<?php

include_once("translator.php");

class wikini2wikka extends Translator {

  function __construct() {
    $this->add('/={6}[ ]*(.*)[ ]*={6}/','<h1>$1</h1>'); // h1
  }

}

?>
