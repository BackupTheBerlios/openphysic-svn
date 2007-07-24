<?php

$unit="mm";

$paper_width = 210; // mm
$paper_height = 297; // mm

$xoffset = 5; // mm
$yoffset = 5; // mm

$line_width = 200; // mm
$line_height = 290; // mm
$xbigspace = 10; // mm
$ybigspace = 10; // mm
$xlittlespace = 1; // mm
$ylittlespace = 1; // mm

$color1 = "black";
$color2 = "red";

$width1= 2; // pt
$width2= 1; // pt


$nb_lines_x = $line_width/$xbigspace; // 20
$nb_lines_y = $line_height/$ybigspace; // 29


header("Content-type: image/svg+xml");

echo <<<HEAD
<?xml version="1.0" encoding="utf-8"?>
<svg
   xmlns="http://www.w3.org/2000/svg" 
   xmlns:xlink="http://www.w3.org/1999/xlink"
   xmlns:ev="http://www.w3.org/2001/xml-events"
   version="1.1"
   baseProfile="full"
   x="0"
   y="0"
   width="$paper_width$unit"
   height="$paper_height$unit"
   id="svg2">
  <title>papier</title>
  <defs id="defs4" />
  <g id="layer1">

HEAD;
?>

<!-- Lignes horizontales -->

<?php
// Lignes horizontales (major)
$x1 = 0+$xoffset;
$y1 = 0+$yoffset;
$x2 = $line_width+$xoffset;
$y2 = $y1; // idem

for ($i = 0 ; $i<$nb_lines_y ; $i++) {
echo <<<MIDDLE_HZ
    <line
       x1="$x1$unit" y1="$y1$unit"
       x2="$x2$unit" y2="$y2$unit"
       stroke="$color1"
       stroke-width="$width1" />

MIDDLE_HZ;
$y1 = $y1 + $ybigspace;
$y2 = $y1;
}

?>

<!-- Lignes verticales -->

<?php
// Lignes verticales (major)
$x1 = 0+$xoffset;
$y1 = 0+$yoffset;
$x2 = $x1; // idem
$y2 = $line_height+$yoffset;

for ($j = 0 ; $j<$nb_lines_x ; $j++) {
echo <<<MIDDLE_VT
    <line
       x1="$x1$unit" y1="$y1$unit"
       x2="$x2$unit" y2="$y2$unit"
       stroke="$color1"
       stroke-width="$width1" />

MIDDLE_VT;
$x1 = $x1 + $xbigspace;
$x2 = $x1;
}

// Lignes horizontales (minor)
// ToDo

// Lignes verticales (minor)
// ToDo

// Dernière ligne horizontale (major)
$x1 = 0+$xoffset;
$y1 = $line_height+$yoffset;
$x2 = $line_width+$xoffset;
$y2 = $y1; // idem
echo <<<LAST_HZ
    <line
       x1="$x1$unit" y1="$y1$unit"
       x2="$x2$unit" y2="$y2$unit"
       stroke="$color1"
       stroke-width="$width1" />

LAST_HZ;

// Dernière ligne verticale (major)
$x1 = $line_width+$xoffset;
$y1 = 0+$yoffset;
$x2 = $x1; // idem
$y2 = $line_height+$yoffset;
echo <<<LAST_VT
    <line
       x1="$x1$unit" y1="$y1$unit"
       x2="$x2$unit" y2="$y2$unit"
       stroke="$color1"
       stroke-width="$width1" />

LAST_VT;


echo <<<END
  </g>
</svg>

END;

?>