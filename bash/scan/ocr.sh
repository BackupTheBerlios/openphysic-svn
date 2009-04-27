#!/usr/bin/env bash
echo "Starting OCR"
# input files are .png
# they are converted to .tif using ImageMagick
# OCR software (tesseract) is applied to create .txt file
for file in *.png;
do
  from=$file
  base=$(basename $file .png)
  to=$base.tif
  echo " Processing $from"
  echo "  Convert $from to $to"
  convert $file $(basename $file .png).tif
  echo "  OCR of $to to create $base.txt"
  tesseract $(basename $file .png).tif $(basename $file .png) -l fra
done
echo "End of jobs"
rm *.tif
#cat *.txt > all.txt
