//////////////////////////////////////////////////////////////////////
//
//                             X-Foot
//
// Copyright � 2001 - 2007, Cedric Ronvel, Pierre Guilluy
//
// Contact: estariel@x-foot.net
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//////////////////////////////////////////////////////////////////////////////

#ifndef _ADVANCED_EXAMPLE_H_
#define _ADVANCED_EXAMPLE_H_

#include "aisdk.h"

////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// [EN] Advanced_Example_AI herits from X_Foot_AI which is the base pattern    
// of a X-Foot AI and assumes the communication with X-Foot program
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// [FR] Advanced_Example_AI h�rite de X_Foot_AI qui est un canevas de base    
// d'une IA pour X-Foot	et se charge de la communication avec X-Foot  
////////////////////////////////////////////////////////////////////////

class Advanced_Example_AI : public X_Foot_AI
{

public :

	Advanced_Example_AI () ;
	virtual ~Advanced_Example_AI () ;

protected:
	
	////////////////////////////////////////////////////////////////////////
	// [EN]
	// The three following methods must be implemented to create a 
	// valid AI :					  
	// [FR]
	// Les trois m�thodes suivantes doivent obligatoirement				  
	// �tre impl�ment�es pour obtenir une IA valide :					  
	////////////////////////////////////////////////////////////////////////		
		
	// [EN]
	// This method is called once, during the connection between the AI and X-Foot,
	// and allows to init informations about the team (team name, players names, etc).
	// [FR]
	// Cette m�thode est appel�e UNE seule fois, pendant la connection de l'IA � X-Foot,
	// et permet d'initialiser les informations sur l'�quipe (nom de l'�quipe, nom des joueurs, etc).
	virtual void configure ( TeamConfigurator& );

	// [EN]
	// This method is called once, just before the beginning of the match and
	// allows the AI to init itself (i.e. load files or create objects) and to compute
	// all heavy operations which couldn't be done once the match's started.
	// The match begins just after the call of this method.
	// [FR]
	// Cette m�thode est appel�e UNE seule fois, juste avant le d�but du match
	// permettant � l'IA de s'initialiser (charger des fichiers ou cr�er des objets par 
	// exemple) et de faire toutes les op�rations couteuses qu'elle n'aura pas 
	// le temps de faire une fois le match lanc�; le match commence imm�diatement apr�s 
	// l'appel de cette m�thode.
	virtual void init ( const Parameter &);

	// [EN] 
	// This method is called on each new situation (about 30 times per second),
	// it receives a reference to the current situation as an input, allows to give 
	// an order to each player and send a message which will be displayed by X-Foot during
	// the match.	
	// [FR]
	// Cette m�thode est appel�e � chaque nouvelle situation (soit 30 fois par
	// seconde), elle recoit en entr�e une r�f�rence sur la situation courante, 
	// permet de donner un ordre � chacun des joueurs et d'envoyer un message qui
	// sera affich� par X-Foot pendant le match.
	virtual void update ( const Situation&, OrdersManager&, ChatterBox& );

private :

	////////////////////////////////////////////////////////////////////////
	// [EN] Here are the advanced example specific data:
	// [FR] Ici se trouvent les donn�es sp�cifiques � l'advanced example:	  
	////////////////////////////////////////////////////////////////////////		

	// [EN]
	// In this advanced example, we implement the goal keeper behaviour
	// and some placement rules for the other players:		
	// [FR]
	// Dans cet exemple avanc�, on va coder le comportement du gardien de but et quelques r�gles
	// de placement pour les joueurs de champs:

	void preliminaries ( const Situation& ) ;
	// [EN] some interesting computing
	// [FR] quelques calculs int�ressants

	void goalkeeper ( const Situation&, OrdersManager&, ChatterBox& ) ;
	// [EN] deal with the goal keeper move
	// [FR] g�re les d�placement du gardien

	void player ( const Situation&, OrdersManager&, ChatterBox& ) ;
	// [EN] deal with the field players
	// [FR] g�re les joueurs de champs
	


	// [EN] calculated values during the preliminaries phase:
	// [FR] Variables calcul�es par la phase pr�liminaire:

	bool we_got_the_ball ;
	// [EN] true if we've last interacted
	// [FR] est vrai si on a la derni�re interaction
	
	int n_proche_allie ;	
	// [EN] id of the nearest player of my team ( the id+1 numbered shirt because an array begins at 0 instead of 1)
	// [FR] indice de l'allie le plus proche ( c-a-d no de maillot -1 car les tableaux commencent par 0 au lieu de 1 )
	
	int dist_proche_allie ;
	// [EN] distance from this player to the ball in centimeters ( X-Foot base unit )
	// [FR] distance de cet allie au ballon en centim�tre ( l'unit� utilis� dans x-foot )  ( vive le syst�me m�trique !!! )
	
	int n_proche_adversaire ;
	// [EN] id of the nearest adversary player ( same remark )
	// [FR] indice de l'adversaire le plus proche ( m�me remarque )
	
	int dist_proche_adversaire ;
	// [EN] distance from this adversary player to the ball
	// [FR] distance de cet adversaire au ballon 	
	
	int n_couvre_allie ;	
	// [EN] id of the nearest player of my team ( the id+1 numbered shirt because an array begins at 0 instead of 1)
	// [FR] indice de l'allie le plus proche ( c-a-d no de maillot -1 car les tableaux commencent par 0 au lieu de 1 )

	int dist_couvre_allie ;
	// [EN] distance from this player to the ball in centimeters ( X-Foot base unit )
	// [FR] distance de cet allie au ballon en centim�tres ( l'unit� utilis� dans x-foot )  ( vive le syst�me m�trique !!! )

	int n_passe_allie ;	
	// [EN] id of the nearest player of my team ( the id+1 numbered shirt because an array begins at 0 instead of 1)
	// [FR] indice de l'allie le plus proche ( c-a-d no de maillot -1 car les tableaux commencent par 0 au lieu de 1 )

	int dist_passe_allie ;
	// [EN] distance from this player to the ball in centimeters ( X-Foot base unit )
	// [FR] distance de cet allie au ballon en centim�tre ( l'unit� utilis� dans x-foot )  ( vive le syst�me m�trique !!! )

	int n_def_adversaire ;
	// [EN] id of the nearest adversary player ( same remark )
	// [FR] indice de l'adversaire le plus proche ( m�me remarque )

	int dist_def_adversaire ;
	// [EN] distance from this adversary player to the ball
	// [FR] distance de cet adversaire au ballon 	
	
	short3 virtual_ballPos ;
	// [EN] virtual position of the ball
	// [FR] position virtuelle du ballon

	int Ref_x[11] ;
	int Ref_y[11] ;
	// [EN] players reference coordinates, they go there when they don't have anything special to do
	// [FR] coordonn�es des positions de r�f�rence des joueurs, quand ils ont rien � faire, ils vont l�
	
	int Limite ;
	int Attaque ;
	int Milieu ;
	int Defense ;

	Parameter param;
	// [EN] the original Parameter is stored here, it contains all the static data concerning a match:
	// the both teams players name, halftime duration, arbiter rules level, etc.
	// [FR] On sauvegardera ici la structure Parameter qui contient toute les donn�es
	// fig�es de la partie, tel le nom des joueurs, la dur�e d'une mi-temps, la force d'arbitrage, etc. 
	
};

////////////////////////////////////////////////////////////////////////

#endif // _ADVANCED_EXAMPLE_H_

