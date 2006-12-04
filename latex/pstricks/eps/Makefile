input=main

all:
	latex $(input).tex
	dvips -E -o $(input).eps $(input).dvi

clean:
	$(RM) *.aux *~ *.log *.dvi *.eps