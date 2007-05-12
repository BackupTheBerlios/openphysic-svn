clear;

s = loadwave("son1_code.wav");
//plot(s);
fmin = 20;
fmax = 20000;
fs = 44100; // frq = 44kHz // echantillonnage
n = 1/fs * size(s,'c'); // duree en s

//analyze(s,fmin,fmax,rate=fs);

t = soundsec(n, fs);


// filtre passe-bas avec frequence coupure 12800 Hz

// modulation AM avec porteuse 12800 Hz

// filtre passe-bas avec frequence coupure 12800 Hz
