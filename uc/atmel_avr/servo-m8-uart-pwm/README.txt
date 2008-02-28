Ce projet d�crit le fonctionnement d'un testeur de servo de mod�lisme.
Il permet de commander un servomoteur � l'aide d'une tension continue (A2D_MODE) ou � l'aide d'une liaison s�rie (UART_MODE) et g�n�re un signal compatible avec les servomoteurs utilis�s en mod�lisme c'est � dire un signal p�riodique de 20 ms et de largeur d'impulsion variable entre 1 et 2 ms.
N�cessite :
- WinAVR-gcc
- AVRLib

R�les des diff�rents cavaliers (JUMPER)
JP2_MODE 0=A2D_MODE 1=UART_MODE
JP2_INPUT
 Entr�e analogique sur borne Vin_ext (utilisation d'un g�n�rateur continu ajustable externe entre 0 et 5V) 
 Potentiom�tre
JP VCC / JP MID / JP GND
 Cavaliers permettant d'activer une r�sistance de pull-up afin que la borne ADC0 ne soit pas "en l'air" si le fil ammenant la tension Vin_ext est d�connect�.


ToDo:
 Changer de uC car le code d�passe 8ko !
 Changer le port sur lequel est reli� le cavalier mode (� cause de l'ISP)


Compiler le programme
$ cd repertoire_projet
$ make

Effacer l'ATmega8
$ avrdude -p m8 -c stk500v2 -P COM4 -e

Programmer l'ATMega8
$ cd repertoire_projet
$ avrdude -p m8 -c stk500v2 -P COM4 -U flash:w:main.hex

Passer l'oscillateur interne de l'ATmega8 de 1MHz � 8Mhz
$ avrdude -p m8 -c stk500v2 -P COM4 -t
avrdude> r lfuse
avrdude> w lfuse 0 0xC4