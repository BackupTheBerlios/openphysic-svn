input=main

all:
	latex $(input).tex
	dvips $(input).dvi -o $(input).ps
	ps2pdf $(input).ps $(input).pdf
	open $(input).pdf

clean:
	$(RM) *~ *.dvi *.ps *.pdf *.aux *.log

