#!/usr/bin/perl
#
# Fichier de test de CGI Perl
# ===========================
#
#  installer le serveur Web (Apache)
#
#  V�rifier que le module Perl d'Apache est install�
#
#  Copier le fichier de test
# cp test.cgi /var/www/perl
# ou
# cp test.cgi /var/www/cgi-bin ?
#
#  V�rifier les droits sur le fichier (chmod)
#
#  Ouvrir la page http://127.0.0.1/perl/test.cgi
#
print <<EOF;
<html>
<head>
</head>
<body>
<h1>Test CGI</h1>
</body>
</html>
EOF
