// R�solution num�rique d'une �quation diff�rentielle
// y'' + b y' + c y = d
// on cherche la solution y(x)
// m�thode utilis�e : la fonction ode de Scilab
// plus d'info en tapant help ode dans Scilab
// S. Celles
// 09/02/2007

clear

b = 1; // MODIFIABLE
c = 1; // MODIFIABLE
d = 1; // MODIFIABLE

// on r��crit l'�qua diff sous la forme
// y'' = d - b y' - c y = f(y, t)
// on utilise une repr�sentation d'�tat (voir espace d'�tat)
// c'est � dire on remplace l'�qua diff du second ordre
// par un syst�me de deux �quations diff�rentielles du premier ordre
// on pose u1=y et u2=y'

function [f]=MonSecondMembre(t,u)
  f(1) = u(2)
  f(2) = d - b*u(2) - c*u(1);
endfunction

t0=0;
t=0:0.1:10;
u0 = [0 ; 0]; // y0=0 et y'0=0

[U]=ode(u0,t0,t,MonSecondMembre);

y = U(1,:); // extraction ligne 1

plot(t,y);
