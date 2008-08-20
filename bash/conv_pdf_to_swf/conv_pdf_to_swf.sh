#!//usr/bin/env sh

### BEGIN INFO
# Short-Description: Convert a .pdf presentation to a browsable .swf
# Required-packages :
#  swftools
#   http://www.swftools.org/
#   http://www.swftools.org/pdf2swf_usage.html
#   http://www.quiss.org/swftools/pdf2swf_usage.html
# Description:
#   Convert a .pdf presentation to a browsable .swf
#   The .pdf file is converted to a .swf file
#   The .swf is combined with a template .swf file
#   Size of the resulting file is modified.
# Author: Sebastien Celles <s.celles@gmail.com>
### END INFO

DESC="Convert a .pdf presentation to a browsable .swf"
SCRIPTNAME=`basename $0`

usage()
{
	echo $DESC >&2
	echo "Usage: $SCRIPTNAME input.pdf template.swf output.swf" >&2
	#echo "Usage: $SCRIPTNAME -i input.pdf [-t template.swf] [-o output.swf] [-l loading.swf]" >&2 # ToDo getopts
        #http://doc.msieurx.fr/scripts_bash_howto.htm
	exit 3
        # ./conv_pdf_to_swf.sh gte.pdf SimpleViewer.swf gte.swf
}

msg()
{
  #if [ "$?" = "0" ]; then
	echo "****** $1 ******"
  #else
  #  exit 1
    #echo ""
    #usage
  #fi
}

cmd() # show the command and execute it
{
	echo " > $1"
	`$1`
}

# ToDo : tester le nb de paramètres / erreur de syntaxe ? -> usage

input=
template=
output=
loading=

#input=$1
#template=$2
#output=$3

temp="temp.swf"
temp2="temp2.swf"
#temp3="temp3.swf"

while [ $# -gt 0 ]
do
  case $1 in
  -i|--input)
    input=$2
    shift
    ;;
  -o|--output)
    output=$2
    shift
    ;;
  -t|--template)
    template=$2
    shift
    ;;
  -l|--loading)
    loading=$2
    shift
    ;;
  -h|--help)
    usage
    shift
    ;;
  --)
    shift
    break
    ;;
  -*)
    echo "$SCRIPTNAME: l'option $1 est incorrecte" >&2
    usage
    ;;
  *)
    break
    ;;
  esac
  shift
done

echo "Running: $SCRIPTNAME --input $input --output $output --template $template --loading $loading"

  msg "Converting the documents"
  cmd "pdf2swf -b $input $temp" && \

  msg "Linking a viewer" && \
  swfcombine -o $temp2 $template viewport=$temp && \

  msg "Linking a Preloader" && \
  preloader="PreLoader.swf" && \ # preloader
  loading="loading.swf" && \ # loading animation
  #swfcombine -o $temp2 $preloader loader=$loading movie=$temp2 && \
  swfcombine -o $temp2 $preloader -x 3000 -y 3000 loader=$loading movie=$temp2 && \ 
  #cp $temp2 $temp3 && \

  msg "Correcting the size and framerate" && \
  swfcombine --dummy `swfdump -XY temp.swf` $temp2 -o $output && \

  msg "Embedding the SWF into a html page" && \
  #echo "Copy/paste it in your HTML code"
  swfdump --html $output && \

  msg "Remove temporary files" && \
  rm -f $temp $temp2 $temp3

#else
#  usage
#fi
