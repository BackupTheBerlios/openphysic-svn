// codage d'un son (idem Canal+)
clear;

// definition de l'intervalle de frequance etudie
fmin = 20;
fmax = 20000;

// creation du signal
n = 4; // 4 secondes
fs = 44100; // frq = 44kHz // echantillonnage
t = soundsec(n, fs);
f1 = 1000; // frq fondamental
s = cos(2*%pi*f1*t)+cos(2*%pi*3*f1*t)/9+cos(2*%pi*5*f1*t)/25;
s = s/(10*max(s)); // pour ajuster l'amplitude
savewave("son1.wav",s,fs);
playsnd(s);
//plot(t,s);
//analyze(s,fmin=20,fmax=20000,rate=fs)

// ToDo : passe-bas avec frq coupure 12800 Hz
// filtrage numerique

// Modulation d'amplitude
fM = 12800; // Hz
sM = s.*cos(2*%pi*fM*t);

analyze(sM,fmin,fmax,rate=fs)

savewave("son1_code.wav",sM,fs);
