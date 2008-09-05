<?php

/*
Affiche différentes pages présentes dans l'array $liste
Usage : http://127.0.0.1/php/affich/index.php?page=0
 */

class pages { 
  private $i;

/*
  private $liste=array(
    "page0.php",
    "page1.php",
    "page2.php",
    "page3.php"
  );
*/
  private $liste;

  public function __construct($liste) {
    $this->i=0;
    $this->liste=$liste;
  }

  public function __destruct() {
    echo "DESTRUCT";
  }

/*
  private function set_pages($liste) {
    $this->liste=$liste;
  }
*/

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

  private function get_previous_i() {
    if ($this->i==0) {
      return count($this->liste)-1;
    } else {
      return ($this->i-1);
    }    
  }

/*
  public function goto_next_page() {
    $this->i=$this->get_next_i();
    $this->show();
  }

  public function goto_previous_page() {
    $this->i=$this->get_previous_i();
    $this->show();    
  }
*/

  private function show() {
    echo "Show page n $this->i : {$this->liste[$this->i]}<br>\n";
    include $this->liste[$this->i];
    //$this->goto_next_page();
    $url_next= "{$_SERVER['PHP_SELF']}?page=" . $this->get_next_i();
    $url_previous= "{$_SERVER['PHP_SELF']}?page=" . $this->get_previous_i();
    $_POST['page']=2;
    echo "<a href='$url_next'>Page suivante<br></a>\n";
    echo "<a href='$url_previous'>Page pr&eacute;c&eacute;dente<br></a>\n";


  }

  public function goto_page($i) {
    $this->set_i($i);
    $this->show();
  }
}


/*
$list = new pages();

$list->set_pages(
  array(
    "page0.php",
    "page1.php",
    "page2.php",
    "page3.php"
  )
);
*/

$list = new pages(
  array(
    "page0.php",
    "page1.php",
    "page2.php",
    "page3.php"
  )
);

$page=$_GET['page'];
if (!is_numeric($page)) {
  $page=0;
}

$list->goto_page($page);

?>
