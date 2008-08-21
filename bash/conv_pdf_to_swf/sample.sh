#!/usr/bin/env bash

msg()
{
  echo "========== $1 =========="
}

cmd() # show the command and execute it
{
  echo " >> $1"
  eval $1
  if [ "$?" != "0" ]; then
    echo " !!!! Error - test script stopped !!!!"
    exit 1 # stop the script in case of error
  fi
}

msg "Convert from .odp"
cmd "./presentation2swf.sh -i sample.odp -o sample.swf -t SimpleViewer.swf -l loading.swf"

#msg "Convert from .ppt"
#cmd "./presentation2swf.sh -i sample.ppt -o sample.swf -t SimpleViewer.swf -l loading.swf"

msg "Make an index.htm"
html='
<html>
  <head>
    <title>index.html</title>
  </head>
  <body>
    <h1>Test page</h1>
  </body>
</html>
'
$html > index.htm


msg "Show it with default browser"
cmd "xdg-open index.html"
