input=main_in
script=main
output=main_out

all:
	perl $(script).pl
	latex $(output).tex
	xdvi $(input).dvi

.PHONY: clean

clean:
	$(RM) $(output).tex