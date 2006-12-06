SOURCES := $(wildcard *.tex)
IMAGES := $(patsubst %.tex,%.eps,$(wildcard *.tex))

all : $(IMAGES) son.sty
	$(MAKE) $<

%.dvi : %.tex son.sty
	latex $<

%.eps : %.dvi
	dvips -E -o $@ $<
	#epstool or psfixbb to get _always_ the correct bounding box
	#ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/ghostgum/epstool-3.08.tar.gz
	epstool --copy --bbox $@ $@.tmp
	mv $@.tmp $@
	#psfixbb (Perl)
	#http://www.tug.org/tex-archive/support/psfixbb/
	#psfixbb $(input).eps
	$(MAKE) cleantemp

.PHONY: clean cleantemp

cleantemp:
	$(RM) *.aux *~ *.log *.dvi

clean :
	$(RM) *.aux *~ *.log *.dvi *.eps