# Effacer fichier *.*~
 > file.txt
for file in `cat file.txt`
do
  svn remove $file
done