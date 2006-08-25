all:
	$(MAKE) html

dvi:
	latex main.tex
	latex main.tex
	bibtex main
	latex main.tex
	xdvi main.dvi &

clean:
	$(RM) *~ *.aux *.blg *.bbl *.log *.dvi

html:
	bibtex2html s-celles.bib
	firefox s-celles.html &
