all:
	python main.py
	#cat main.tex
	pdflatex main.tex
	xpdf main.pdf

.PHONY: clean

clean:
	$(RM) *.log *~ *.tex *.pdf *.aux
