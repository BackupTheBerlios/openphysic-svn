Turbojet WrenTrubines MW54 Mk3 Turbo-Jet Kit with Autostart
http://wrenturbines.co.uk

ECU FADEC
http://www.espiell.com/soft.htm
http://www.espiell.com/fadprot.pdf Protocole de communication série

VI Labview pour le contrôle du turbojet
par S. CELLES
	test_turbo_serial.vi : VI permettant la visualisation des données depuis l'ECU connecté via la liaison série (cable USB Xicoy)
		read_serial_turbo.vi : sous-VI connexion série et chaîne de caractères en sortie
	test_sim_turbo.vi : VI simulant l'envoi des trames par l'ECU et visulisant les données
		sim_turbo_rs232.vi : sous-VI simulant l'envoi des trames par l'ECU (chaîne de caractères en sortie)
			fixed_string : sous-VI générant une chaîne de taille définie à partir d'une autre chaîne	
		read_buffer_turbo_rs232.vi : sous-VI découpant la chaîne de caractère pour former un cluster comportant les données lues sur la liaison série
