<html>
  <head>
    <title>Scroll an iframe</title>
    <script language="javascript" src="autoscroll.js"></script>
  </head>

  <body onLoad="pageScroll(document.getElementById('mydata').contentDocument, window.frames[0])">
  <!-- <body onLoad="pageScroll(document.getElementById('mydata').contentDocument.body, window.frames.getElementById('mydata'))"> -->

    <!-- <h1 onclick="debug()">iFrame</h1> -->

    <!-- <iframe id="mydata" src="content.php" height="100%" width="100%" frameborder="0"> -->
    <iframe id="mydata" src="http://www.rfc-editor.org/rfc/rfc2606.txt" height="100%" width="100%" frameborder="0">
      Alternative text for browsers that do not understand IFrames.
    </iframe>
  </body>

</html>
