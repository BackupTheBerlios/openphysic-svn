#ifndef LCD_H
#define LCD_H
/*************************************************************************
 Title	:   C include file for the HD44780U LCD library (lcd.c)
 Author:    Peter Fleury <pfleury@gmx.ch>  http://jump.to/fleury
 File:	    $Id: lcd.h,v 1.12.2.3 2004/12/09 21:05:17 peter Exp $
 Software:  AVR-GCC 3.3
 Hardware:  any AVR device, memory mapped mode only for AT90S4414/8515/Mega

***************************************************************************/

/**
 @defgroup Lcd Librairie LCD de type HD44780U.
 @code #include  <sup_avr/lcd.c> @endcode

 @brief Routines pour interfacer un afficheur LCD de type D44780U

 Originally based on Volker Oth's LCD library,
 changed lcd_init(), added additional constants for lcd_command(),
 added 4-bit I/O mode, improved and optimized code.

 Library can be operated in memory mapped mode (LCD_IO_MODE=0) or in
 4-bit IO port mode (LCD_IO_MODE=1). 8-bit IO port mode not supported.

 Memory mapped mode compatible with Kanda STK200, but supports also
 generation of R/W signal through A8 address line.

Modification (pour utiliser le delay_us)
Ajout des caract�res sp�ciaux et de la gestion des accents fran�ais
Ajout des fonctions lcd_Remplis, lcd_EcrisTexteLong et lcd_AfficheAuCentre
traduction en fran�ais
Adaptation � la carte du Lyc�e Aristide BRIAND
par Frank SAURET

 @author Peter Fleury pfleury@gmx.ch http://jump.to/fleury

 @see The chapter <a href="http://homepage.sunrise.ch/mysunrise/pfleury/avr-lcd44780.html" target="_blank">Interfacing a HD44780 Based LCD to an AVR</a>
      on my home page. Un super editeur <a href="http://anyedit.free.fr" target="_blank">AnyEdit</a>
*/

/*@{*/

#if (__GNUC__ * 100 + __GNUC_MINOR__) < 303
	#error "This library requires AVR-GCC 3.3 or later, update to newer AVR-GCC compiler !"
#endif

#include <inttypes.h>
#include <avr/pgmspace.h>


// scls
//#define N 1 // scls for VMLAB warning Flag N must be set to '1' in dispalys with lines > 1



/**
 *  @name  D�finition de la taille de l'affichage
 *  � adapter � son afficheur
 */
#define LCD_LINES           4     /**< Nombre de ligne de l'afficheur */
#define LCD_DISP_LENGTH    20     /**< Nombre de caract�re visible par ligne 16 */
#define LCD_LINE_LENGTH  0x40     /**< Longueur de la ligne interne de l'afficheur   */
#define LCD_START_LINE1  0x00     /**< Adresse DDRAM du 1er caract�re de la ligne 1 (00) */
#define LCD_START_LINE2  0x40     /**< Adresse DDRAM du 1er caract�re de la ligne  2 (40) */
#define LCD_START_LINE3  0x14     /**< Adresse DDRAM du 1er caract�re de la ligne  */
#define LCD_START_LINE4  0x54     /**< Adresse DDRAM du 1er caract�re de la ligne  4 */
#define LCD_WRAP_LINES      0     /**< 0: pas de d�calage, 1: d�calage � la fin de la ligne visible*/



#define LCD_IO_MODE      1         /**< 0: Mode adressage, 1: mode port E/S */
#if LCD_IO_MODE
	/**
	 *  @name Definitions pour le mode port E/S 4-bit
	 *  Changer LCD_PORT selon votre structure.
	 *
	 *  Les 4 lignes de donn�es et les lignes de contr�le RS, RW, E
	 *  peuvent �tre sur le m�me port ou sur des ports diff�rents
	 *  Changer LCD_RS_PORT, LCD_RW_PORT, LCD_E_PORT.
	 *
	 *
	 */
	#define LCD_PORT         PORTE        /**< Port pour le LCD  			*/
	#define LCD_DATA0_PORT   LCD_PORT     /**< Port pour la ligne D4 		*/
	#define LCD_DATA1_PORT   LCD_PORT     /**< Port pour la ligne D5 		*/
	#define LCD_DATA2_PORT   LCD_PORT     /**< Port pour la ligne D6 		*/
	#define LCD_DATA3_PORT   LCD_PORT     /**< Port pour la ligne D7 		*/
	#define LCD_DATA0_PIN    4            /**< PIN pour la ligne D4  		*/
	#define LCD_DATA1_PIN    5            /**< PIN pour la ligne D5  		*/
	#define LCD_DATA2_PIN    6            /**< PIN pour la ligne D6  		*/
	#define LCD_DATA3_PIN    7            /**< PIN pour la ligne D7  		*/
	#define LCD_RS_PORT      PORTF	     /**< Port pour la ligne RS 		*/
	#define LCD_RS_PIN       5            /**< PIN pour la ligne	 		*/
	#define LCD_RW_PORT      PORTF   	  /**< Port pour la ligne RW 		*/
	#define LCD_RW_PIN       6            /**< PIN pour la ligne     		*/
	#define LCD_E_PORT       PORTF   	  /**< Port pour la ligne Enable */
	#define LCD_E_PIN        7            /**< PIN pour la ligne Enable  */

	#elif defined(__AVR_AT90S4414__) || defined(__AVR_AT90S8515__) || defined(__AVR_ATmega64__) || \
		  defined(__AVR_ATmega8515__)|| defined(__AVR_ATmega103__) || defined(__AVR_ATmega128__) || \
		  defined(__AVR_ATmega161__) || defined(__AVR_ATmega162__)
	/*
	 *  Le mode adressage est support� uniquement si il y a une interface adapt�e.
	 */
	#define LCD_IO_DATA      0xC000    /* A15=E=1, A14=RS=1                 */
	#define LCD_IO_FUNCTION  0x8000    /* A15=E=1, A14=RS=0                 */
	#define LCD_IO_READ      0x0100    /* A8 =R/W=1 (R/W: 1=Read, 0=Write   */
	#else
		#error "Pas d'interface pour le mode adressage. Utiliser le mode 4 bit."

#endif


/**
 *  @name D�finitions des commandes pour le LCD
 *  Les constantes d�finissent les diff�rentes commandes qui peuvent �tre
 * 	pass�e au contr�lleur du LCD
 *  fonction lcd_command(), voir la data sheet du HD44780 pour une description compl�te.
 */

/* Registre et bit, voir la doc du HD44780U */
#define LCD_CLR               0      /**< DB0: Efface l'�cran.                  */
#define LCD_HOME              1      /**< DB1: Retour en haut � gauche.        */
#define LCD_ENTRY_MODE        2      /**< DB2: met en entr�e.                 */
#define LCD_ENTRY_INC         1      /**<   DB1: 1=incr�ment, 0=d�crement.     */
#define LCD_ENTRY_SHIFT       0      /**<   DB2: 1= D�calage de l'affichage on.         */
#define LCD_ON                3      /**< DB3: Allumage de l'�cran et du curseur.             */
#define LCD_ON_DISPLAY        2      /**<   DB2: Extinction de l'affichage.          */
#define LCD_ON_CURSOR         1      /**<   DB1: Allumage du curseur.                */
#define LCD_ON_BLINK          0      /**<     DB0: Curseur clignotant ?          */
#define LCD_MOVE              4      /**< DB4: D�place le curseur / l'affichage.           */
#define LCD_MOVE_DISP         3      /**<   DB3: D�place l'affichage (0-> curseur) ?  */
#define LCD_MOVE_RIGHT        2      /**<   DB2: D�place � droite (0-> Gauche) ?      */
#define LCD_FUNCTION          5      /**< DB5: jeux de fonctions.                   */
#define LCD_FUNCTION_8BIT     4      /**<   DB4: Mode 8BIT (0-> Mode 4BIT). */
#define LCD_FUNCTION_2LINES   3      /**<   DB3: 2 lignes (0->1 ligne).      */
#define LCD_FUNCTION_10DOTS   2      /**<   DB2: Police 5x10 (0->Police 5x7).     */
#define LCD_CGRAM             6      /**< DB6: set CG RAM address             */
#define LCD_DDRAM             7      /**< DB7: set DD RAM address             */
#define LCD_BUSY              7      /**< DB7: LCD occup�.                   */

/**< set entry mode: display shift on/off, dec/inc cursor move direction */
#define LCD_ENTRY_DEC            0x04   /**< display shift off, dec cursor move dir */
#define LCD_ENTRY_DEC_SHIFT      0x05   /**< display shift on,  dec cursor move dir */
#define LCD_ENTRY_INC_           0x06   /**< display shift off, inc cursor move dir */
#define LCD_ENTRY_INC_SHIFT      0x07   /**< display shift on,  inc cursor move dir */

/**< display on/off, cursor on/off, blinking char at cursor position */
#define LCD_DISP_OFF             0x08   /**< Extinction de l'affichage.                             */
#define LCD_DISP_ON              0x0C   /**< Allumage de l'�cran extinction du curseur.  */
#define LCD_DISP_ON_BLINK        0x0D   /**< Allumage de l'�cran et curseur �teint et clignotant. */
#define LCD_DISP_ON_CURSOR       0x0E   /**< Allumage de l'�cran et du curseur. */
#define LCD_DISP_ON_CURSOR_BLINK 0x0F   /**< Allumage de l'�cran et curseur clignotant. */

/**< move cursor/shift display */
#define LCD_MOVE_CURSOR_LEFT     0x10   /**< D�place le curseur � gauche (d�cr�ment).          */
#define LCD_MOVE_CURSOR_RIGHT    0x14   /**<  D�place le curseur �  droite (incr�ment).          */
#define LCD_MOVE_DISP_LEFT       0x18   /**<D�cale l'affichage � gauche.                   */
#define LCD_MOVE_DISP_RIGHT      0x1C   /**< D�cale l'affichage � droite. */

/**< function set: set interface data length and number of display lines */
#define LCD_FUNCTION_4BIT_1LINE  0x20   /**< Interface 4-bit, 1 ligne, 5x7 points */
#define LCD_FUNCTION_4BIT_2LINES 0x28   /**< Interface 4-bit, 2 lignes,   5x7 points */
#define LCD_FUNCTION_8BIT_1LINE  0x30   /**< Interface 8-bit, 1 ligne, 5x7 points */
#define LCD_FUNCTION_8BIT_2LINES 0x38   /**< Interface 8-bit, 2 lignes,   5x7 points */


#define LCD_MODE_DEFAULT     ((1<<LCD_ENTRY_MODE) | (1<<LCD_ENTRY_INC) )
/**
	 *  @name DCaract�res sp�ciaux et variables de d�filement
	 *
	 */
#define	Alpha	0xE0 /**< Code pour g�n�rer le caract�re Alpha*/
#define	Teta	0xF2 /**< Code pour g�n�rer le caract�re T�ta*/
#define	Epsilon	0xE3 /**< Code pour g�n�rer le caract�re Epsilon*/
#define	Infinit	0xF3 /**< Code pour g�n�rer le symbole Infinit*/
#define	Micro	0xE4 /**< Code pour g�n�rer le caract�re �*/
#define	Omega	0xF4/**< Code pour g�n�rer le caract�re Omega*/
#define	SigmaMin	0xE5/**< Code pour g�n�rer le caract�re sigma minuscule*/
#define	Rho	0xE6/**< Code pour g�n�rer le caract�re rho */
#define	SigmaMaj	0xF6/**< Code pour g�n�rer le caract�re sigma majuscule*/
#define	Pi	0xF7/**< Code pour g�n�rer le caract�re Pi*/
#define	Racine	0xE8/**< Code pour g�n�rer le caract�re Racine carr�*/
#define	XBarre	0xF8/**< Code pour g�n�rer le caract�re X barre*/
#define	Divise	0xFD/**< Code pour g�n�rer le caract�re division*/
#define	Degre	0xDF/**< Code pour g�n�rer le caract�re degr�*/
#define	FlecheDroite	0x7E/**< Code pour g�n�rer le caract�re fl�che droite*/
#define	FlecheGauche	0x7F/**< Code pour g�n�rer le caract�re fl�che gauche*/
#define	Guillemet	0x22/**< Code pour g�n�rer le caract�re "*/
#define	Carre	0xFF/**< Code pour g�n�rer un rectangle noir */
#define	PointCentral	0xA5/**< Code pour g�n�rer un point centrale */
#define	DroiteGauche	0/**< Constante de direction */
#define	GaucheDroite	1/**< Constante de direction */

//extern ??? Pourquoi pas ??? Compatbilit� C/C++
unsigned char AccentsFrancais=1;/**< Active l'utilisation des accents fran�ais. lcd_ChargeAccentsFrancais le met � 1*/
/*
** D�finition de constantes
*/

 /**
 @brief    D�finition des caract�res sp�cifiques au fran�ais (� � � � � � � �).
 */
static const PROGMEM unsigned char CaracteresAccentues[] =
{
  /**<D�finition du �*/
	0b00010, 0b00100, 0b01110, 0b10001, 0b11111, 0b10000, 0b01110, 0b00000,
	/**<D�finition du �*/
	0b01000, 0b00100, 0b01110, 0b10001, 0b11111, 0b10000, 0b01110, 0b00000,
	/**<D�finition du �*/
	0b00100, 0b01010, 0b01110, 0b10001, 0b11111, 0b10000, 0b01110, 0b00000,
	/**<D�finition du �*/
	0b01010, 0b00000, 0b01110, 0b10001, 0b11111, 0b10000, 0b01110, 0b00000,
	/**<D�finition du �*/
	0b01000, 0b00100, 0b01110, 0b00001, 0b01111, 0b10001, 0b01111, 0b00000,
	/**<D�finition du �*/
	0b01000, 0b00100, 0b10001, 0b10001, 0b10001, 0b10011, 0b01101, 0b00000,
	/**<D�finition du �*/
	0b01110, 0b10000, 0b10000, 0b10001, 0b01110, 0b00100, 0b01000, 0b00000,
	/**<D�finition du �*/
	0b00100, 0b01010, 0b01110, 0b10001, 0b10001, 0b10001, 0b01110, 0b00000
};

/**
 *  @name Fonctions.
 */


/**
 @brief    Initialise l'affichage et le type de curseur.
 @param    dispAttr \b LCD_DISP_OFF Eteint l'affichage.\n
                    \b LCD_DISP_ON Allume l'affichage, �teint le curseur.\n
                    \b LCD_DISP_ON_CURSOR Allume l'affichage, allume le curseur.\n
                    \b LCD_DISP_ON_CURSOR_BLINK Allume l'affichage, le curseur clignote.
 @return  	Rien
*/

extern void lcd_init(uint8_t dispAttr);

/**
 @brief    Efface l'�cran et  remet le curseur en haut � gauche
 @param    Aucun
 @return   Rien
*/
extern void lcd_clrscr(void);

/**
 @brief    Met le curseur en haut � gauche
 @param    Aucun
 @return   Rien
*/
extern void lcd_home(void);

/**
 @brief    D�place le curseur.

 @param	x : Position horizontale (0: le plus � gauche).
 @param  y : Position verticale   (0: premi�re ligne).
 @return   Rien
*/
extern void lcd_gotoxy(uint8_t x, uint8_t y);

/**
 @brief    Affiche un caract�re � la position courante
 @param  c : caract�re � afficher
 @return   Rien
*/
extern void lcd_putc(char c);

/**
 @brief    Affiche une chaine (sans saut de ligne)
 @param  s : chaine � afficher
 @return   Rien
*/
extern void lcd_puts(const char *s);

/**
 @brief    Affiche une chaine de la m�moire (sans saut de ligne)
 @param  progmem_s : chaine de la m�moire � afficher
 @return   Rien
 @see      lcd_puts_P
*/
extern void lcd_puts_p(const char *progmem_s);

/**
 @brief    Envoie une commande au LCD
 @param  cmd : Commande � envoyer. Voir la data sheet du HD44780.
 @return   Rien
*/
extern void lcd_command(uint8_t cmd);

/**
 @brief    Envoie une donn�e au LCD

 Identique � lcd_putc(), sans interpr�tation du LF
 @param  data : donn�e(byte) � envoyer. Voir la data sheet du HD44780.
 @return   Rien
*/
extern void lcd_data(uint8_t data);

/**
 @brief macros pour charger automatiquement une constante dans la m�moire.
*/
#define lcd_puts_P(__s)         lcd_puts_p(PSTR(__s))

/**
 @brief    Remplis l'affichage avec un caract�re.

 @param  s : Caract�re de remplissage.
 @param  delay : Intervalle entre deux caract�res.
 @param  sens : Sens du remplissage.
*/
extern void lcd_Remplis(char s, uint8_t delay, uint8_t sens);

/**
 @brief    Ecrit un texte qui d�file tout seul.

 Cette fonction de haut niveau est � pr�f�rer aux autres fonction (lcd_puts, lcd_putc)
car elle g�re toute seule le d�passement de l'�cran.
Elle ne g�re pas le saut de ligne (\\n).
@param		s : Texte � �crire.
@param		x : Colonne  du premier caract�re.
@param		y :  Ligne.
@param		xfinal : Colonne  (en partant de la droite) du dernier caract�re.
@param		delay : Intervalle de temps entre 2 d�calages.
@return   Rien
@warning Dans certaine configuration, un bug apparait : ajout de qqs caract�res en fin de texte puis supression de ceux-ci.
 Ce bug est apparu avec la commande suivante :
 lcd_EcrisTexteLong("Ceci est un.", 5,  0, 7, 500);
Il ne c'est pas produit dans d'autres configurations et je ne l'ai pas encore trouv�.
*/
extern void lcd_EcrisTexteLong(const char *s, char x, char y, char xfinal, unsigned int delay);

/**
 @brief    Charge dans la CGRAM les caract�res accentu�s fran�ais.
					aux emplacement : 	\n 		0	1	2	3	4	5	6	7
													    \n 		�	�	�	 �	�	�	�	�

  @return   Rien
*/
extern void lcd_ChargeAccentsFrancais(void);

/**
 @brief    Affiche une chaine au centre de la ligne
@param		s : Chaine � afficher
@param 	y : Ligne d'affichage

  @return   Rien
*/
extern void lcd_EcrisAuCentre(const char *s, uint8_t y);
/*@}*/
#endif //LCD_H







