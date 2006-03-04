// Position des charges
OA = [0 0 0]; // en m
q = [1]; // en C

Ncharge=size(q,'r');

// Point où l'on calcule le champ 
OM = [2 2 0]; // en m

// Constantes
epsilon0 = 8.85418781762E-12;
ke = 1/(4*%pi*epsilon0);

// Définition des bornes de l'espace
xmin = -2; xmax = 2; xstep = 0.5;
ymin = -2; ymax = 2; ystep = 0.5;
zmin = -2; zmax = 2; zstep = 0.5;

DATA = [];
OM_DATA = [];
E_DATA = [];
V_DATA = [];

for z=zmin:zstep:zmax,
   for y=ymin:ystep:ymax,
      for x=xmin:xstep:xmax,
         for i=1:Ncharge,
            OM = [x y z];

            // Vecteur charge -> point où on mesure le champ
            AM = OM - OA(i,:);

            // Calcul du champ électrique E
            if norm(AM) <> 0 then
               E = ke * q(i,1) / norm(AM)^3 * AM;
               V = ke * q(i,1) / norm(AM);
            else
               E = [0 0 0];
               V = 0;
            end
         
            //DATA = [DATA; OM E V];
            OM_DATA = [OM_DATA; OM];
            E_DATA = [E_DATA; E];
            V_DATA = [V_DATA; V];
         end
      end
   end
end

DATA = [OM_DATA E_DATA V_DATA]
