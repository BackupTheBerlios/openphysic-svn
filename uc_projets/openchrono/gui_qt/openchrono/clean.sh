# clean obj files
make clean
rm Makefile
qmake openchrono.pro

# remove temporary files~
rm src/*~ *~

# beautify code (astyle, GNU/Indent...)
astyle --style=gnu src/*.cpp src/*.h
rm src/*.orig

# informations about project
sloccount src/

# make documentation (doxygen)