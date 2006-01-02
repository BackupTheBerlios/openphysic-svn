#export CVSROOT=toto@cvs.mon-organisation.com:/opt/cvs
export CVSROOT=scls19fr@cvs.sourceforge.net:/cvsroot/openphysic
export CVS_RSH=ssh
export CVSEDITOR=emacs

#cvs -z3 -d:ext:scls19fr@cvs.sourceforge.net:/cvsroot/openphysic co -P CVSROOT


cd ~

#cvs checkout CVSROOT

cvs checkout doc_classe_latex_phys_ch_pha

# cvs -> local
  # cvs update

# local -> cvs
  # cvs commit


