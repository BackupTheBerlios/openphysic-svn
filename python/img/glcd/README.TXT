Ce script est r�alis� en Python avec PIL (Python Imaging Library).

Il transforme une image (glcd.bmp) en un fichier source en C qui contient les donn�es � envoyer � un microcontr�leur pour un afficheur graphique LCD (type T6963 ou KS0108B)

$ make
pr�requis :
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
	
	D�filement
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
	240x128
	Monochrome bitmap (1bpp)
	Table horizontal from left to right
	Origin at Top Left
	MSB First

KS0108B
	240x128
	Monochrome bitmap (1bpp)
	Table vertical downwards
	Origin at Top Left
	MSB Last


	
ToDo :

Am�lioration de la classe GController
	pb avec Enum ?
	faire des tests pour v�rifier l'�galit�
	(s'inspirer de la classe Origin ? rendre les autres classes (Paging, Color) plus "g�n�rique")
	Il faut que la description des options possible apparaisse
	Utiliser un dictionnaire (dict {'cle': valeur} )

Am�lioration de glcd.py
	En faire une classe
	Faire fonction usage()
	Eviter les tests sur les noms de controleur graphique
		�viter par exemple gc.name == "T6963"
		mais utiliser les propri�t�s de ce type de controleur
		(->il faut d'abord am�liorer GController)

Faire d'autres writers
	#"\tretlw\t0x%02X\n" % byte # ASM TAB MICROCHIP PIC
	#"	DA	0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00" # ASM DATA MICROCHIP PIC
	#"	.db	0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00" # ASM DATA ATMEL
	#"fcb$00 , $00 , $00 , $00 , $00 , $00 , $00 , $00" # ASM DATA ATMEL
	#Pix(0,0) = &H2A& : Pix(0,1) = &H20& : Pix(0,2) = &H00& : Pix(0,3) = &H00& # VB

Rendre les writers appelables via une cha�ne de caract�re et g�n�rer automatiquement les "from writer_ import Writer_"
	M�canisme de plugin ?
	
Possibilit� de passer un writer_perso dans la ligne de commande (?)
	option -W chemin/vers/writer_perso.py (au lieu de -w writer_name)
	$ python glcd.py picture.bmp -g T6963 -l c -W chemin/vers/writer_perso.py
	
G�rer des afficheurs en niveaux de gris et en couleurs (pas uniquement monochrome)

Rajouter en d�but de prog la possibilit� de remettre � l'�chelle (� piori r�tr�cir) l'image afin qu'elle rentre dans l'afficheur
	voir cr�ation de thumbnail avec PIL
	conserver le ratio w/h (combler par des pixels vide sinon)
