all:
	$(MAKE) html

dvi:
	latex main.tex
	latex main.tex
	bibtex main
	latex main.tex
	xdvi main.dvi &

.PHONY: clean dvi html bib2html bibtex2html

clean:
	$(RM) *~ *.aux *.blg *.bbl *.log *.dvi

html:
	$(MAKE) bibtex2html

bib2html:
	# http://www.arakhne.org/IMG/deb/bib2html_4.3-1_all.deb (Perl)
	bib2html -f s-celles.bib

bibtex2html:
	# http://www.lri.fr/~filliatr/bibtex2html/index.en.html (OCalm)
	bibtex2html s-celles.bib
	firefox s-celles.html &
