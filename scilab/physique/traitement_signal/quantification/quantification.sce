clear;

function sq=quantif(s,N)
	 sq=round(s)
endfunction

n=0.005 // duree
N=3; // nb de bits
f=500
rate=44100; // frq echantillonnage
// rate assez �lev�e car on veut mettre en �vidence
// la quantification... pas l'�chantillonnage
t=soundsec(n, rate);
s=(2^N-1)*(sin(2*%pi*f*t)+1)/2; // signal �chantillonn� mais pas quantifi�
sq=quantif(s,N); // signal quantifi�
err=abs(s-sq)^2; // erreur (bruit) de quantification 
plot(t,s,t,sq,t,err);

