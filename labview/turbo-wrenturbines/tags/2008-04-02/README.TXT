Turbojet WrenTrubines MW54 Mk3 Turbo-Jet Kit with Autostart
http://wrenturbines.co.uk

ECU FADEC
http://www.espiell.com/soft.htm
http://www.espiell.com/fadprot.pdf Protocole de communication s�rie

VI Labview pour le contr�le du turbojet
par S. CELLES
	test_turbo_serial.vi : VI permettant la visualisation des donn�es depuis l'ECU connect� via la liaison s�rie (cable USB Xicoy)
		read_serial_turbo.vi : sous-VI connexion s�rie et cha�ne de caract�res en sortie
	test_sim_turbo.vi : VI simulant l'envoi des trames par l'ECU et visulisant les donn�es
		sim_turbo_rs232.vi : sous-VI simulant l'envoi des trames par l'ECU (cha�ne de caract�res en sortie)
			fixed_string : sous-VI g�n�rant une cha�ne de taille d�finie � partir d'une autre cha�ne	
		read_buffer_turbo_rs232.vi : sous-VI d�coupant la cha�ne de caract�re pour former un cluster comportant les donn�es lues sur la liaison s�rie

button_press.vi
menu_down.vi / menu_up.vi / data_up.vi / data_down.vi
sous-vi gestion du clavier

stick_trim_2_channel.vi : sous-vi tranformant la valeur du stick (0-100%) et la valeur du trim(-100% ; 100%) en une information (channel value) comprise entre 0 et 100%
test_stick_trim.vi : test du sous-vi stick_trim_2_channel.vi

channel_2_pulsewidth.vi / channel_2_u8.vi / channel_2_u16.vi / channel_2_vdc.vi : sous-vi tranformant une information channel value en largeur d'impulsion (us), entier non sign� sur 8 bits (U8), entier non sign� sur 16 bits (U16), en tension continu entre 0 et 5V

calibration_stick_trim.vi : sous-vi �talonnage du stick/trim afin de r�gler la position pour l'arr�t, le ralenti et la pleine puissance


ToDo
Testeur de servo USB avec drivers FTDI D2XX
voir ouverture et fermeture du handle du mat�riel
