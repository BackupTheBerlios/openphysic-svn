#!/usr/bin/env perl
open STDOUT, "> main.tex";

$x=1;
$y=2;
$z= $x + $y;

print <<EOF;
\\documentclass[12pt,a4paper]{article}

\\usepackage[french]{babel}     % specification francaise
\\usepackage[latin1]{inputenc}   % entree clavier latin1
\\usepackage[T1]{fontenc}        % sortie

\\title{Calcul num�rique en \\LaTeX{} avec Perl}
\\author{S. Celles}
%\date{\\today}
\\date{\\null}

\\begin{document}

\\maketitle


\\section*{Introduction}
Cet exemple a pour objectif de montrer l'utilisation de \LaTeX{}
coupl� avec Perl pour r�aliser des documents <<dynamiques>>, c'est �
dire des documents r�alis�s avec \LaTeX{}, comportants du calcul num�rique dont les valeurs
sont recalcul�es � la vol�e par le langage de script Perl.

\\section{Premier exemple}
\\begin{itemize}
\\item La variable x vaut $x\\\\
\\item La variable y vaut $y\\\\
\\item La variable z = x + y vaut $z
\\end{itemize}


\\end{document}
EOF

