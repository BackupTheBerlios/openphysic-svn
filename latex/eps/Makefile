input=main

all:
	latex $(input).tex
	dvips -E -o $(input).eps $(input).dvi
	#to get _always_ the correct bounding box
	#epstool --copy --bbox main.eps main.tmp
	#mv main.tmp main.eps

to get _always_ the correct bounding box. 

clean:
	$(RM) *.aux *~ *.log *.dvi *.eps