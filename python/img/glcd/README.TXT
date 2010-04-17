Ce script est réalisé en Python avec PIL (Python Imaging Library).

Il transforme une image (glcd.bmp) en un fichier source en C qui contient les données à envoyer à un microcontrôleur pour un afficheur graphique LCD (type T6963 ou KS0108B)

$ make
prérequis :
installer Python + PIL (Python Imaging Library)


voir aussi :
http://www.abcelectronique.com/bigonoff/biglcd.php?par=1f3e1
http://bitmap2lcd.com/

Config :
	Taille Afficheur
		96x40 100x32 112x64 120x32 122x32 128x32 128x64 128x128 144x32 160x32 160x80 160x128 160x160? 192x32 192x64 192x128 240x64 240x128 320x240? User defined
		
	Couleurs
		Monochrome bitmap (1bpp)
		16 gray levels bitmap (4bpp)
		255 colors (8 bpp)
		4096 colors (12bpp)
		65535 colors (16bpp)
	
	Défilement
		Table horizontal from left to right
		Table horizontal from right to left
		Table vertical downwards
		Table vertical upwards
	
	Origin
		Origin at Top Left
		Origin at Bottom Left
		
	Most signifiant bit MSB
		MSB First
		MSB Last

Exemples :
T6963
	Monochrome bitmap (1bpp)
	Table horizontal from left to right
	Origin at Top Left
	MSB First

KS0108B
	Monochrome bitmap (1bpp)
	Table vertical downwards
	Origin at Top Left
	MSB Last