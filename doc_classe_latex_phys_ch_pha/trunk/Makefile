input=main
page=0

all:
	#$(MAKE) view-pdf
	$(MAKE) view-ps

.PHONY: main.dvi clean view-ps view-pdf view-pdf-dvips view-pdf-pdflatex edit view-ps-2 only.tex this brouillon clean_temp

$(input).dvi: #$(input).tex s-celles.sty elec_intro/main2.tex elec_sin/main2.tex
	latex $(input).tex

$(input).ps: $(input).dvi
	dvips $< -o $@

$(input)_dvips.pdf: $(input).ps
	ps2pdf $< $@
	cp $(input)_dvips.pdf $(input).pdf

view-dvi: $(input).dvi
	xdvi -bg white $< &

view-ps: $(input).ps
	gv $< &

view-pdf:
	$(MAKE) view-pdf-dvips

view-pdf-dvips: $(input)_dvips.pdf
	xpdf $< &

view-pdf-pdflatex: $(input)_pdflatex.pdf
	xpdf $< &

clean_temp:
	$(RM) temp/*

clean:
	$(RM) *.aux *.log *.dvi *.ps *.pdf
	$(MAKE) clean_temp
	$(MAKE) clean_select
	$(MAKE) clean_only

edit:
	emacs *.tex Makefile *.sty &


$(input)_suite_2.ps: $(input).ps
	psnup -n 2 $< > $@

view-ps-2: $(input)_suite_2.ps
	gv --orient=landscape $< --page=$(page) &


$(input)_dvips_suite_2.pdf: $(input)_dvips.pdf
	pdfnup --nup 2 $< --orient landscape --outfile $@

view-pdf-dvips-2: $(input)_dvips_suite_2.pdf
	xpdf $< &

$(input)_pdflatex_suite_2.pdf: $(input)_pdflatex.pdf
	pdfnup --nup 2 $< --orient landscape --outfile $@

view-pdf-2:
	$(MAKE) view-pdf-dvips-2

view-pdf-pdflatex-2: $(input)_dvips_pdflatex_2.pdf
	xpdf $< &

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
	xpdf $(input)_select.pdf &

clean_select:
	$(RM) $(input)_select.*



clean_only:
	$(RM) only*

only.tex:
	$(MAKE) clean_only
#	file=elec/tp_i_u/main2.tex
	file=title.tex
	perl make_only.pl $(file)


only.dvi: only.tex
	latex $<

only.ps: only.dvi
	dvips $< -o $@

only-ps: only.ps
	gv $< &

only_suite_2.ps: only.ps
	psnup -n 2 $< > $@

only-ps2: only_suite_2.ps
	gv --orient=landscape $< &

only-pdf: only.pdf
	xpdf $< &

#make only-pdf2 file=title.tex
only-pdf2: only_suite_2.pdf
	xpdf $< &

only.pdf: only.ps
	ps2pdf only.ps only.pdf

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
