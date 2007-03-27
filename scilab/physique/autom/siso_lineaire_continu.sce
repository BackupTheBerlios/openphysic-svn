clear;
xdel;

s=poly(0,'s');
tau1=1;
H=syslin('c',1/(1+tau1*s));

// Correcteur
// ==========
//C=syslin('c',1);

// Réponse fréquentielle
// =====================
//bode(H,1E-2,1E2);
//black(H)
//nyquyst(H)

//halt(); // pause
//xbasc(); // effacer ecran

// Calculs
// =======
//pôles et zéros (roots) d'un polynome (voir aussi poly)

// Réponse temporelle
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


