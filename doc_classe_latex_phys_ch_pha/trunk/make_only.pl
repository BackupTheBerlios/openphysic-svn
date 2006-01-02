#!/usr/bin/perl
open STDOUT, "> only.tex";

print <<BEGIN_OF_ONLY_TEX;
\\documentclass[a4paper,10pt]{book}
\\usepackage{s-celles}
\\begin{document}
BEGIN_OF_ONLY_TEX


    print "\\input{$ARGV[0]}\n";



print <<END_OF_ONLY_TEX;
\\end{document}
END_OF_ONLY_TEX
