// Résolution numérique d'une équation différentielle
// y'' + b y' + c y = d
// on cherche la solution y(x)
// méthode utilisée : la fonction ode de Scilab
// plus d'info en tapant help ode dans Scilab
// S. Celles
// 09/02/2007

b = 1; // MODIFIABLE
c = 1; // MODIFIABLE
d = 1; // MODIFIABLE

// on réécrit l'équa diff sous la forme
// y'' = d - b y' - c y = f(y, t)
// on utilise une représentation d'état (voir espace d'état)
// c'est à dire on remplace l'équa diff du second ordre
// par un système de deux équations différentielles du premier ordre
// on pose u1 = y et u2=y'

function f=f(t,u)
  f = d - b*y(2) - c*u(1);
endfunction

t0=0;
t=0:0.1:10;
u0 = [1 ; 0]; // y0=1 et y'0=0
y=ode(u0,t0,t,f);

//plot(t,y);
