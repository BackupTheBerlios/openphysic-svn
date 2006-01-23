input=main

page=0

dvi_viewer=xdvi
ps_viewer=gv
pdf_viewer=xpdf #acroread #xpdf

do=view-ps

all:
	$(MAKE) $(do)
	#$(MAKE) view-pdf
	#$(MAKE) view-ps

# Permet d'accélérer la compilation
# en évitant une sortie sur la console
# et en l'envoyant sur /dev/null
# Exemple : make dvi stdout=/dev/null stderr=/dev/null
#stdin=/dev/stdin
#stdout=/dev/stdout
#stderr=/dev/stderr

# Raccourcis pour pouvoir taper par exemple `make pdf'
dvi: $(input).dvi
ps: $(input).ps
ps2: $(input)_suite_2.ps
pdf: $(input)_dvips.pdf
pdf2: $(input)_dvips_suite_2.pdf


.PHONY: all main.dvi clean view-ps view-pdf view-pdf-dvips view-pdf-pdflatex edit view-ps-2 only.tex this brouillon clean_temp distclean

$(input).dvi: #$(input).tex s-celles.sty elec_intro/main2.tex elec_sin/main2.tex
	latex $(input).tex

$(input).ps: $(input).dvi
	dvips $< -o $@

$(input)_dvips.pdf: $(input).ps
	ps2pdf $< $@
	cp $(input)_dvips.pdf $(input).pdf

view-dvi: $(input).dvi
	$(dvi_viewer) -bg white $< &

view-ps: $(input).ps
	$(ps_viewer) $< &

view-pdf:
	$(MAKE) view-pdf-dvips

view-pdf-dvips: $(input)_dvips.pdf
	$(pdf_viewer) $< &

view-pdf-pdflatex: $(input)_pdflatex.pdf
	$(pdf_viewer) $< &

clean_temp:
	$(RM) temp/*

clean:
	#$(RM) $(input).{toc,log,aux,out,dvi,ps,pdf} *~
	$(RM) *.aux *.log *.dvi *.ps *.pdf *.toc *.out semantic.cache*
	$(MAKE) clean_temp
	$(MAKE) clean_select
	$(MAKE) clean_only

distclean: clean

edit:
	emacs *.tex Makefile *.sty &


$(input)_suite_2.ps: $(input).ps
	psnup -n 2 $< > $@

view-ps-2: $(input)_suite_2.ps
	$(ps_viewer) --orient=landscape $< --page=$(page) &


$(input)_dvips_suite_2.pdf: $(input)_dvips.pdf
	pdfnup --nup 2 $< --orient landscape --outfile $@

view-pdf-dvips-2: $(input)_dvips_suite_2.pdf
	$(pdf_viewer) $< &

$(input)_pdflatex_suite_2.pdf: $(input)_pdflatex.pdf
	pdfnup --nup 2 $< --orient landscape --outfile $@

view-pdf-2:
	$(MAKE) view-pdf-dvips-2

view-pdf-pdflatex-2: $(input)_dvips_pdflatex_2.pdf
	$(pdf_viewer) $< &

zip:
	$(RM) $(input).zip
	zip -r $(input).zip *

ftp:
	ncftpput -u s.cls ftpperso.free.fr realisations/phys_latex Makefile s-celles.sty main.tex *.pl *.pdf $(input).zip

#*.ps *.dvi

ftp_full_build:
	ncftpput -u s.cls ftpperso.free.fr realisations/phys_latex/full_build Makefile s-celles.sty main.tex *.pl *.pdf $(input).zip *.ps

get:
	rm -r $(input).zip
	wget http://s.cls.free.fr/realisations/phys_latex/$(input).zip
	unzip $(input).zip



select: $(input).ps
	#$ make select page=39
	page=1
	psselect -p$(page) $(input).ps $(input)_select.ps
	ps2pdf $(input)_select.ps $(input)_select.pdf
	$(pdf_viewer) $(input)_select.pdf &

clean_select:
	$(RM) $(input)_select.*



clean_only:
	$(RM) only*

only.tex:
	$(MAKE) clean_only
#	file=elec/tp_i_u/main2.tex
	file=title.tex
	perl make_only.pl $(file)
#	Utiliser GNU M4 au lieu de Perl ?


only.dvi: only.tex
	latex $<

only.ps: only.dvi
	dvips $< -o $@

only-ps: only.ps
	$(ps_viewer) $< &

only_suite_2.ps: only.ps
	psnup -n 2 $< > $@

only-ps2: only_suite_2.ps
	$(ps_viewer) --orient=landscape $< &

only-pdf: only.pdf
	$(pdf_viewer) $< &

#make only-pdf2 file=title.tex
only-pdf2: only_suite_2.pdf
	$(pdf_viewer) $< &

only.pdf: only.ps
	ps2pdf $< $@

only_suite_2.pdf: only.pdf
	pdfnup --nup 2 $< --orient landscape --outfile $@

this:
	$(MAKE) only-ps2 file=thermodynamique/tp3_chaleur_latente_fusion_glace/main2.tex
#	$(MAKE) only-ps2 file=title.tex
#	$(MAKE) only-ps file=title.tex



brouillon:
	$(MAKE) only-ps file=brouillons/main2.tex


scan:
	scanimage > temp/image.eps



mini.dvi: mini.tex
	latex $<

mini.ps: mini.dvi
	dvips $< -o $@

mini-ps: mini.ps
	$(ps_viewer) $< &

mini_suite_2.ps: mini.ps
	psnup -n 2 $< > $@

mini-ps2: mini_suite_2.ps
	$(ps_viewer) --orient=landscape $< &

mini-pdf: mini.pdf
	$(pdf_viewer) $< &

mini-pdf2: mini_suite_2.pdf
	$(pdf_viewer) $< &

mini.pdf: mini.ps
	ps2pdf $< $@

mini_suite_2.pdf: mini.pdf
	pdfnup --nup 2 $< --orient landscape --outfile $@

commit_pdf:
	cp main.pdf pdf/
	cp main_dvips_suite_2.pdf pdf/
	svn commit

commit:
	svn commit

update:
	svn update

version:
	svn propset svn:keywords "Id" version.tex

status:
	svn status

rubber:
	# http://www.pps.jussieu.fr/~beffara/soft/rubber
	rubber --ps $(input)

silent:
	$(MAKE) $(do) > /dev/null 2> /dev/null
	# Accélère la compilation (pas de sortie console)
	#make silent do=pdf
	#stdout=/dev/null stderr=/dev/null stdin=/dev/null