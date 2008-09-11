<?php

/*
Affiche différentes pages présentes dans l'array $liste
Principe : les différentes pages à afficher sont placées
 dans différents iframes.
 Tous les iframes sont cachés sauf celui à afficher
 */

class pages { 
  //private $i;

  private $liste;

  private $default_timeout;

  public function __construct($liste) {
    //$this->i=0;
    $this->liste=$liste;
    $this->default_timeout=4000;
  }

  public function __destruct() {
    //echo "DESTRUCT";
  }

  public function nb() {
   return count($this->liste)-1;
  }

/*
  private function set_pages($liste) {
    $this->liste=$liste;
  }
*/

/*
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
*/

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

  public function set_timeout($t) {
    $this->default_timeout=$t;
  }

  private function get_timeout() {
    return $this->default_timeout;
  }

  public function show() {
echo "<html>
  <head>
    <title>Afficheur avec iframes cach&eacute;s</title>
  </head>

  <body onload=\"update()\">

  <script type=\"text/javascript\"><!--

var i_affich = 2;

function goto_next_page() {
  i_affich=get_next_i();
}

setTimeout('update()',{$this->get_timeout()});

function update()
{
//  Cache tous les iframes
for(i=0;i<={$this->nb()};i++) {
  document.getElementById(\"page\"+i).style.display=\"none\"; // ou style.visibility=\"hidden\"
}

// Affiche l'iframe actuel
document.getElementById(\"page\"+i_affich).style.display=\"\";

//setTimeout('update()',{$this->get_timeout()}); // refresh périodique
}
// --></script>

";

for ($i=0;$i<=count($this->liste)-1;$i++) {
echo "
    <iframe id=\"page$i\" name=\"page$i\" src=\"{$this->liste[$i]}\" height=\"100%\" width=\"100%\" >
      Alternative text for browsers that do not understand IFrames.
    </iframe>
";
}
// frameborder=\"0\"

echo "
  </body>

</html>";

  }

/*
  public function goto_page($i) {
    if (!is_numeric($i)) {
      $i=0;
    }
    $this->set_i($i);
    $this->show();
  }
*/
}

?>
