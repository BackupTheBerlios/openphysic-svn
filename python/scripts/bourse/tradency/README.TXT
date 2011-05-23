A voir

http://www.trader-forex.fr/forum/systemes-de-trading-auto/11080-fxcm-system-selector-fss-6.html
http://www.mataf.net/forums/Tradency-1-Mois-De-Test-t17146.html


2011-05-22
	History.xls
	MyHistory.xls
	Portfolio.xls
	
TODO:
	Faire script pour analyser les positions et qui calcule
	(pour un intervalle de temps donné ou pour tout)
		nb de transactions
		total pips
		% trades gagnants
		% trades perdants
		Max DD
		PM
		Facteur de Profit
		Temps de Trade Moyen
		Pips moyen par trade
		Gain de Trade Moyen (pips)
		Perte de Trade Moyenne (pips)
		Trade Profitable Maximal (pips)
		Perte de Trade Maximale (pips)
		Rollover ($)
		Symboles Tradés
		
	Calculer le nb de trades avec un total pips dans tel ou tel intervalle
		principe : on définit les bornes ex :
			[0] x<=0 x>0
				renvoie [nb_x_negatif, nb_x_positif_strictement]
			[-10, 10] x<-10 -10<=x<10 x>=10
				renvoie [nb_x_inf_-10, nb_x_entre_-10_et_10, nb_x_sup_10]
			[-10, 0, 10] x<-10 -10<=x<0 0<=x<10 x>=10
				renvoie [nb_x_inf_-10, nb_x_entre_-10_et_10, nb_x_sup_10]

			Rem 1 : trier avant la liste (ou tuple)
			Rem 2 : attention aux bornes <= ou < ?
			Le script renvoie une liste de taille = taille + 1
			
			si bornes = [] on renvoie len()
			
	Simuler la mise en place d'un stop loss (SL) sur une stratégie existante

	Simuler la mise en place d'un take profil (TP) sur une stratégie existante

	Optimiser le SL et le TP à partir d'une stratégie existante
	
	Calculer les pips gagnés à partir du cours d'entrée et de sortie (et de la direction SELL ou BUY)
		(dépend de la paire traitée)
		Pip stands for percentage in point. A pip is equal to 1/100th of 1 percent
	
	Calculer le profit en EUR (en fonction du nb de pips)
	
	Calculer valeur interpolée dans temps
		y = (yb-ya)/(tb-ta)*(t-ta)+ya
		[[t1, y1], [t2, y2], ...] (t croissant)
		trouver y à un t quelconque (ne pas extrapoler)