Cr�er dans le home deux liens symboliques
ln -s profile ~/.profile
ln -s profile ~/.bashrc

Script AppleScript mountsmb.app
Montage de r�pertoires Samba depuis Mac OS X

try
    mount volume "smb://ccti@192.168.0.2/doc_ccti"
end try

try
    mount volume "smb://192.168.0.2/public"
end try

try
    mount volume "smb://192.168.0.2/photo"
end try

Lancement automatique du script au d�marrage
de la session d'un utilisateur
Pr�f�rences Syst�me / Comptes / Mon compte / Ouverture
