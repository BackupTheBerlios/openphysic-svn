clear;
xdel;

s=poly(0,'s');
tau1=1;
H=syslin('c',1/(1+tau1*s));

// Correcteur
// ==========
//C=syslin('c',1);

// R�ponse fr�quentielle
// =====================
//bode(H,1E-2,1E2);
//black(H)
//nyquyst(H)

//halt();

// Calculs
// =======
//p�les et z�ros (roots) d'un polynome (voir aussi poly)

// R�ponse temporelle
// ==================
t=(0:0.01:5)';
y=csim('step',t,H);
plot(t,y);


// Chaine de retour
// ================
// feedback (/.)
