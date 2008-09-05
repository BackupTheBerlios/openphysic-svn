<?php

/*
Affiche différentes pages présentes dans l'array $liste
Usage : http://127.0.0.1/php/affich/index.php?page=0
 */

$config=array(
  afficheur=>'http://127.0.0.1/php/affich/index.php?page='
);

class pages { 
  private $i;
  private $liste=array(
    "page0.php",
    "page1.php",
    "page2.php",
    "page3.php"
  );

  public function __construct() {
    $this->i=0;
  } 
  public function __destruct() {
    echo "DESTRUCT";
  }

  private function set_i($i) {
    if ($i<=count($this->liste)-1) {
      $this->i=$i;
    } else {
      $this->i=0;
    }
  }

  private function get_next_i() {
    if ($this->i==count($this->liste)-1) {
      return 0;
    } else {
      return ($this->i+1);
    }
  }

/*
  private function get_previous_i() {
    
  }
*/

  private function goto_next_page() {
    $this->i=$this->get_next_i();
    //echo $this->i;
  }

/*
  public function goto_previous_page() {
    
  }
*/

  private function show() {
    echo "Show page n $this->i : {$this->liste[$this->i]}<br>\n";
    include $this->liste[$this->i];
    $this->goto_next_page();
    echo "<a href='#'>Page suivante<br></a>";
    echo "<a href='#'>Page pr&eacute;c&eacute;dente<br></a>";
  }

  public function goto_page($i) {
    $this->set_i($i);
    $this->show();
  }
}



$list = new pages();

$page=$_GET['page'];
if (!is_numeric($page)) {
  $page=0;
}

$list->goto_page($page);

?>
