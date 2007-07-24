<?php

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
   width="300"
   height="200"
   id="svg2">

HEAD;

echo <<<MIDDLE
  <title>Rectangles</title>
  <defs
     id="defs4" />
  <g
     id="layer1">
    <rect
       width="300"
       height="120"
       x="0"
       y="20"
       fill="green"
       id="rect1306" />
    <rect
       width="80"
       height="150"
       x="20"
       y="30"
       fill="red"
       id="rect1308" />
    <rect
       width="140"
       height="80"
       x="50"
       y="50"
       fill="blue"
       id="rect1310" />
  </g>

MIDDLE;

echo <<<END
</svg>

END;

?>