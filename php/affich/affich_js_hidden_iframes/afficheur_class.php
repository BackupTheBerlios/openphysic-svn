<?php

/*
Affiche différentes pages présentes dans l'array $liste
Principe : les différentes pages à afficher sont placées
 dans différents iframes.
 Tous les iframes sont cachés sauf celui à afficher
 */

class pages { 
  private $liste;
  private $default_timeout;

  public function __construct($liste) {
    $this->liste=$liste;
    $this->default_timeout=4000;
  }

  public function __destruct() {
  }

  public function nb() {
   return count($this->liste)-1;
  }

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

var i_affich = 0;

function next_page() {
  if (i_affich=={$this->nb()}) {
    i_affich=0;
  } else {
    i_affich++;
  }
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

next_page();

setTimeout('update()',{$this->get_timeout()}); // refresh périodique
}
// --></script>

";

for ($i=0;$i<=count($this->liste)-1;$i++) {
echo "
    <iframe id=\"page$i\" name=\"page$i\" src=\"{$this->liste[$i]}\" height=\"100%\" width=\"100%\" frameborder=\"0\">
      Alternative text for browsers that do not understand IFrames.
    </iframe>
";
}

echo "
  </body>

</html>";

  }

}

?>
