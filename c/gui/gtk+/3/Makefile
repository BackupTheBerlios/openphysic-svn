input=main

all:
	gcc $(input).c -o $(input) `pkg-config --cflags --libs gtk+-2.0`

clean:
	$(RM) $(input)