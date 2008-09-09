<html>
  <head>
    <title>Scroll an iframe</title>
    <script language="javascript" src="autoscroll.js"></script>
  </head>

  <body onLoad="pageScroll(document.getElementById('mydata').contentDocument.body, window.frames[0])">
    <h1 onclick="debug()">iFrame</h1>

    <iframe id="mydata" src="content.php" height="100%" width="100%" frameborder="0">
      Alternative text for browsers that do not understand IFrames.
    </iframe>
  </body>

</html>
