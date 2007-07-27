#Linux
DEFAULT_INCLUDE=/usr/lib/include
TCL_INCLUDE=$(DEFAULT_INCLUDE)
PYTHON_INCLUDE=$(DEFAULT_INCLUDE)


#Mac OS X
TCL_INCLUDE=/system/Library/Frameworks/Tcl.framework/Versions/Current/Headers #/usr/local/include
PYTHON_INCLUDE=/system/Library/Frameworks/Python.framework/Versions/Current/include/python2.3/

all:
	#$(MAKE) tcl
	$(MAKE) python

tcl:
	swig -tcl example.i
	gcc -c -fPIC example.c example_wrap.c -I$(TCL_INCLUDE) -I$(DEFAULT_INCLUDE)
	gcc -shared example.o example_wrap.o -o libexample.so
	#tclsh
#% load ./libexample.so
#% fact 4
#24
#% my_mod 23 7
#2
#% expr $My_variable + 4.5
#7.5
#%

python:
	swig -python example.i
	PYDIR=/system/Library/Frameworks/Python.framework/Versions/Current/
	gcc -I $(PYDIR) -framework Python -bundle -bundle_loader $PYDIR/bin/python example.c example_wrap.c -o libexample.so


.PHONY: clean

clean:
	$(RM) *~ *.o *.so