#!/usr/bin/env python

import zipfile
import os

print "Zip files in a directory (and its subdirectories)"

dir="files"

zip=zipfile.ZipFile("files.zip", 'w')


#walking in the directories and subdirectories
root=''
dirs=[]
files=[]
for root, dirs, files in os.walk(dir, topdown=True):
  for file in files:
    print os.path.join(root, file)
    zip.write(os.path.join(root, file))

zip.close()