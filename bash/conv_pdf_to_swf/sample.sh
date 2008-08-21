#!/usr/bin/env bash

### BEGIN INFO
# Short-Description: Convert a presentation to a browsable .swf
# Required-scripts :
#  presentation2swf.sh
# Required-packages :
#  see presentation2swf.sh
# Description:
#   Convert a presentation to a browsable .swf
#   Test presentation2swf.sh
# Author: Sebastien Celles <s.celles@gmail.com>
### END INFO

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

input=sample.odp #.odp .ppt
output=sample.swf

#msg "Convert from .odp"
#cmd "./presentation2swf.sh -i sample.odp -o sample.swf -t SimpleViewer.swf -l loading.swf"

#msg "Convert from .ppt"
#cmd "./presentation2swf.sh -i sample.ppt -o sample.swf -t SimpleViewer.swf -l loading.swf"

msg "Make an HTML file"
cmd "swfdump --html $output > object.html" # ToDo insert it in html code bellow
html='<html>
  <head>
    <title>index.html</title>
  </head>
  <body>
    <h1>Test page</h1>
  </body>
</html>'

url="`pwd`/index.htm" #pwd=print working directory
echo "$html" > $url
cat $url


msg "Show it with default browser"
cmd "xdg-open file://$url"
#cmd "firefox file://$url"


msg "Remove temporary files"
#cmd "rm -f object.html"


