// Loi de d�croissance radioactive
// ===============================

// S. Celles
// 15/08/2005

clear;

// ceci n'est que la partie affichage...
// �a n'est pas �a le plus important.
// mais je suis oblig� de le d�finir au d�but
// pour pouvoir l'appeler ensuite dans le programme
function affiche_noyaux()
	M = zeros(sqrtN,sqrtN); // matrice carr�e remplie de zeros

	// on remplit la matrice avec la liste des noyaux (radioactifs ou d�sint�gr�s)
   for i=1:sqrtN // ligne
     for j=1:sqrtN // colonne
       M(i,j)=ELT(j+(i-1)*sqrtN);
     end
   end

	// on applique la r�gle de couleur suivante :
	//  noir : noyau radioactif
	//  blanc : noyau d�sint�gr�
	M=M*(color("black")-color("white"))+color("white"); 
	
	// on dessine les noyaux !
	//xbasc() // on efface l'�cran
	Matplot(M)

endfunction

function affiche_courbe()
  //xbasc() // effacer l'�cran
  plot(Nlist)
endfunction

function afficher()
  xbasc();
  subplot(2,1,1);
  affiche_noyaux();
  subplot(2,1,2);
  affiche_courbe();
endfunction

function affiche_logn()
  NlistSansZero=Nlist(1:size(Nlist,'r')-1,1);
  //xbasc()
  plot2d(log(NlistSansZero))
endfunction

function affiche_histo()
N1=Nlist(1:size(Nlist,'r')-1); // du premier � l'avant dernier
N2=Nlist(2:size(Nlist,'r')); // du deuxi�me au dernier
Nd=N1-N2;
// Il faut mainteant calculer les fr�quences d'un nombre de d�sint�gration
histplot(size(Nd,'r'),Nd,normalization=%f)
endfunction

// la partie importante du programme commence ici

lines(0);


sqrtN = 25; // sqrtN = 25 : 25 lignes et 25 colonnes soit 625 �l�ments (Nb de lignes et de colonnes)

Nini = sqrtN^2


p0 = 0.2

// Initialisation

j=0; // nb de tirage
ELT = ones(Nini,1); // Matrice colonne repr�sentant
  // les atomes radioactifs (1)
  // ou les atomes d�sint�gr�s (0)
// Initialement tous les atomes sont radioactifs



N=sum(ELT) // nb de noyaux radioactifs
Nlist=[N]; // liste du nb de noyaux radioactifs

afficher();

halt()

// Tirage


while (sum(ELT)>0)
  j=j+1;

  for i=1:Nini
  	 p = rand(); // tirage au sort d'un nombre rnd entre 0 et 1
  	 if p<p0	 // p est inf�rieur � p0 le noyau est d�sint�gr�
      ELT(i,1) = 0;
    end
   	// sinon il reste tel quel ! (on ne fait rien)
  end

  N=sum(ELT) // nb de noyaux radioactifs
  Nlist=[Nlist;N]; // liste du nb de noyaux radioactifs
  afficher();
  halt()
end


printf("Tous les noyaux radioactifs sont desintegres\n");

// L'allure de la courbe N=f(t) est une exponentielle
// On le v�rifie en tra�ant log(N)
// Dans Scilab log = log n�p�rien et log10 = log d�cimal
// Il faut �liminer le dernier point (0)
// car log(0) tend vers l'infini


halt();
//subplot(2,2,4)
xbasc();
affiche_logn();

//halt(),

// On veux montrer le caract�re al�atoire d'une d�sint�gration radioactive
// On trace un histogramme
//  y : nombre de fois o� l'on d�tecte n d�sint�grations
//  x : nombre  de d�sint�grations (intervalles)
//xbasc()
//affiche_histo()
