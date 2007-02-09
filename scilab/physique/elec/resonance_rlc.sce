clear

// d�finition des valeurs num�riques des composants
R=1E3;
L=1;
C=1E-6;

// calcul de la fr�quence de resonance
w0=1/sqrt(L*C);
f0=w0/(2*%pi)
Q = L*w0 / R

// intervalle de fr�quence � consid�rer
f_min=100;
f_max=500;
N=100; // nombre de points
f=[f_min:(f_max-f_min)/N:f_max]'; // vecteur colonne f allant de f_min � f_max
w=2*%pi*f; // pulsation

// imp�dance
Z = R + %i*L*w + 1/(%i*C)*w^(-1); // imp�dance complexe
Zabs = abs(Z); // module de l'imp�dance complexe
Zangle = atan(real(Z),imag(Z)); // argument de l'imp�dance complexe

// courant
U = 2.5/sqrt(2); // U en notation complexe (attention valeur efficace)
I = U * Z^(-1);
Iabs = abs(I);
plot2d(f,Iabs); // affichage

[f Z Zabs Iabs]; // enlever le point-virgule pour afficher les r�sultats
