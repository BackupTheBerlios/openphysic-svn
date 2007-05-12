clear;

s1 = loadwave("son1_code.wav");
//plot(s);
fmin = 20;
fmax = 20000;
fs = 44100; // frq = 44kHz // echantillonnage
n = 1/fs * size(s1,'c'); // duree en s

analyze(s1,fmin,fmax,rate=fs);

t = soundsec(n, fs);


fM =12800;

// filtre passe-bas avec frequence coupure 12800 Hz
//s2 = s1
//analyze(s2,fmin,fmax,rate=fs);

// modulation AM avec porteuse 12800 Hz
//s3 = s2.*cos(2*%pi*fM*t);
//analyze(s3,fmin,fmax,rate=fs);

// filtre passe-bas avec frequence coupure 12800 Hz
//s4 = s3
//analyze(s4,fmin,fmax,rate=fs);

// sauvegarde du son
//savewave("son1_decode.wav",s4,fs);
