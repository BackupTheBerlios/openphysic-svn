// Calcul approch� de %pi
// par S. CELLES
// M�thode : s�rie convergente
//   sum(1/n^2,n=1..infinity)=%pi^2/6 => %pi =

clear

S = 0;

N=5000; // Nb d'it�rations

for i=1:1:N
 	 S = S+1/i^2;
end

sqrt(6*S)
