input = glcd.bmp
output = glcd.c

all:
	$(RM) *.o
	python glcd.py
	#cat $(output)
	gcc -c $(output) -W -Wall -pedantic -ansi

.PHONY: clean

clean:
	$(RM) *.o *.pyc