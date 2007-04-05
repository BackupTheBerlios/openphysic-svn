clear;
xdel;

s=poly(0,'s'); // ou s=%s
tau1=1;
H=syslin('c',1/(1+tau1*s));

// Correcteur
// ==========
// K = 1;
// Ti = 1;
// Td = 1;
// a = ;
//NoC=syslin('c',1);
//Cp = syslin('c',K); // correcteur proportionnel
//Cav_ph = K*(1+a*s)/(1+T*s); // correcteur a avance de phase
//Cret_ph = K*(1+s)/(1+a*T*s); // correcteur a retard de phase
//Cpi = K*(1 + 1/(Ti*s));
//Cpd = K*(1 + Td*s);
//Cpid = K*(1+1/(Ti*s)+Td*s);
//Cpir = // predicteur de Smith
//C = NoC

// Retard : voir approximation de Pade
function y=exp_pade(x) // approximation de Pade
 y = syslin('c',(1+x/2)/(1-x/2)); // ordre 1
 //y = syslin('c',(1+x/2+x^2/12)/(1-x/2+x^2/12)); // ordre 2
 //y = syslin('c',(1+x/2+x^2/10+x^3/120)/(1-x/2+x^2/10-x^3/120)); // ordre 3
endfunction

// Reponse frequentielle
// =====================
//bode(H,1E-2,1E2);
//black(H)
//nyquyst(H)

//halt(); // pause
//xbasc(); // effacer ecran

// Calculs
// =======
//oles et eros (roots) d'un polynome (voir aussi poly)

// Reponse temporelle
// ==================
t=(0:0.01:5)';
y=csim('step',t,H);


// Chaine de retour
// ================
// feedback (/.)
Hbf=H/.ones(1,1); // ones car retour unitaire
ybf=csim('step',t,Hbf);


clf();
drawlater()
subplot(2,1,1);
  plot2d(t,y);
  xtitle("Reponse indicielle en BO","t","y");
subplot(2,1,2)
  plot2d(t,ybf);
  xtitle("Reponse indicielle en BF","t","y");
drawnow()

halt;

clf();
drawlater()
subplot(1,2,1);
  bode(H,1E-2,1E2);
  xtitle("Diagramme de Bode du systeme en BO");
subplot(1,2,2)
  bode(Hbf,1E-2,1E2);
  xtitle("Diagramme de Bode du systeme en BF");
drawnow()


