#!/usr/bin/perl
#
# Fichier de test de CGI Perl
# ===========================
#
#  Installer le serveur Web (Apache)
#
#  V�rifier que le module Perl d'Apache est install�
#
#  Copier le fichier de test
#   cp test.cgi /usr/lib/cgi-bin (Debian)
#    ou
#   cp test.cgi /var/www/perl (Debian)
#    ou
#   cp test.cgi /var/www/cgi-bin (Redhat)
#
#  V�rifier les droits sur le fichier (chmod)
#
#  V�rifier l'interpr�teur perl (pas de pb de r�pertoire)
#
#  V�rifier le script en lan�ant /usr/bin/perl test.cgi
#
#
#  Ouvrir la page http://127.0.0.1/perl/test.cgi
#
print <<EOF;
Content-type: text/html

<html>
    <head>
    <title>Test GUI</title>
    </head>
    <body>
    <h1>Test CGI</h1>
    </body>
</html>
EOF
