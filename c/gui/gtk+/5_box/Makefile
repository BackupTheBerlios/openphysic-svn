input=main
CC=gcc -Wall -W -ansi -pedantic

all:
	$(CC) $(input).c -o $(input) `pkg-config --cflags --libs gtk+-2.0`

clean:
	$(RM) $(input)