n=4; // 4 secondes
fs=44100; // frq = 44kHz
t=soundsec(n, fs);
f1=2200; // frq fondamental
s=cos(f1*t)+cos(3*f1*t)/9+cos(5*f1*t)/25;
s=s/(10*max(s)); // pour ajuster l'amplitude
savewave("son2.wav",s,fs);
