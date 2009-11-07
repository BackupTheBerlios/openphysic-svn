// Remplissage d'une matrice avec
// M(i,j) = f(i,j)
// et affichage de la matrice
// selon une Žchelle de couleur

function f=f(i,j)
	f = i+j
endfunction

lig = [0:0.1:1];
col = [0:0.1:1.2]';

M = zeros(size(lig,'c'), size(col,'r'));

for i=1:size(M,'r')
	for j=1:size(M,'c')
		M(i,j)=f(i,j);
	end
end

M

//colormap

Matplot(M)