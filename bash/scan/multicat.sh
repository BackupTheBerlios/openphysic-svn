#!/usr/bin/env bash
echo "Starting Multicat"
# input files are .txt
# they are concatenat into one all.txt file
rm -f all.txt
for file in *.txt;
do
  cat $file >> all.txt
done
echo "End of jobs"
