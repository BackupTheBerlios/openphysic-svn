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
    //echo "DESTRUCT";
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
    //echo $_GET['page'];
    //echo "<pre>".print_r($this->liste, false)."</pre>";
    //echo "<br>\n";
    //echo print_r($_GET);

    $url_next= "{$_SERVER['PHP_SELF']}?page=" . $this->get_next_i();
    $url_previous= "{$_SERVER['PHP_SELF']}?page=" . $this->get_previous_i();

/*
    echo "<script type=\"text/javascript\"><!--
setTimeout('Redirect()',4000);
function Redirect()
{
 location.href = '$url_next';
}
// --></script>\n";
*/

    //echo "Show page n $this->i : {$this->liste[$this->i]}<br>\n";
    $url_include = $this->liste[$this->i]['url'];

    if ( ! count($this->liste[$this->i]['params']) == 0 ) {
/*
	for ($i=0;$i<count($this->liste[$this->i]['params']);$i++) {
          echo "param $i : {$this->liste[$this->i]['params'][$i]}<br>\n";
        }
*/
        foreach ($this->liste[$this->i]['params'] as $param => $valeur) {
          echo "Key: $param; Value: $valeur<br />\n";
	  $param=$valeur;
          //$_GET['param1']=$valeur;
          //echo print_r($_GET);
        }
    }
    include $url_include;

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
    array(url=>"page0.php"),
    array(url=>"page1.php"),
    array(url=>"page2.php", params=>array(param1=>1, param2=>2)),
    array(url=>"page3.php")
  )
);

 //    page2.php?param=blabla,

$page=$_GET['page'];
if (!is_numeric($page)) {
  $page=0;
}

$list->goto_page($page);

?>
