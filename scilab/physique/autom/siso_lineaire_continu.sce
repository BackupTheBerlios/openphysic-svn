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

//halt();

// Calculs
// =======
//pôles et zéros (roots) d'un polynome (voir aussi poly)

// Réponse temporelle
// ==================
t=(0:0.01:5)';
y=csim('step',t,H);
plot(t,y);


// Chaine de retour
// ================
// feedback (/.)
