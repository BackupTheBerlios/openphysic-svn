input=main

all:
	mpost $(input).mp
	gv $(input).1 &

.PHONY: clean

clean:
	$(RM) *.log *.mpx semantic.cache