# Effacer fichier *.*~
# ceux qui sont versionn�s et les autres
find -name *.*~ > file.txt
for file in `cat file.txt`
do
  svn remove $file
done
svn commit
for file in `cat file.txt`
do
  rm $file
done
