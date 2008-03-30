all:
	python main.py
	#cat main.tex
	pdflatex main.tex
	xpdf main.pdf -fullscreen

.PHONY: clean

clean:
	$(RM) *.log *~ *.tex *.pdf *.aux
