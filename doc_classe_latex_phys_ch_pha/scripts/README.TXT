Remplacer \section par \Section
===============================
- zsh
perl -pi -e 's/\\section/\\Section/g' ./**/*.tex(.)

ou sed -i ...

- bash
find . -name '*.tex' -type f -exec perl -pi -e '
  s/\\section/\\Section/g' {} +

Remplacer $$...$$ par \[ \]
===========================
perl -pi -e '
  s/\$\$(.*?)\$\$/\\[$1\\]/g;' ./**/*.tex

perl -pi -e '
  s{
    \$\$ ((?: \. | .)*?) \$\$ |
    % .*?\n |
    \\verb(.).*?\1 |
    \\. |
    [^\\%\$]+ |
    .
  }{defined($1) ? "\\[$1\\]" : $&}gsxe' ...