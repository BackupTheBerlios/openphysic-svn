// Position des charges
OA = [0 0 0]; // en m
q = [1]; // en C

Ncharge = size(q,'r');

// Point où l'on calcule le champ 
OM = [2 2 0]; // en m

// Constantes
epsilon0 = 8.85418781762E-12;
ke = 1/(4*%pi*epsilon0);

// Définition des bornes de l'espace
xmin = -2; xmax = 2; xstep = 0.5; xlist=xmin:xstep:xmax;
ymin = -2; ymax = 2; ystep = 0.5; ylist=ymin:ystep:ymax;
zmin = -2; zmax = 2; zstep = 0.5; zlist=zmin:zstep:zmax;

DATA = [];
OM_DATA = [];
E_DATA = [];
V_DATA = [];
V_MATRIX = zeros(size(xlist,'c'),size(ylist,'c'));

//for z=zlist,
z = 0;
   for y=ylist,
      for x=xlist,
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
            //V_DATA = [V_DATA; V];
            //V_MATRIX(x,y) = V;
         end
      end
   end
//end

Ex_DATA = E_DATA(:,1);
Ey_DATA = E_DATA(:,2);
Ez_DATA = E_DATA(:,3);

DATA = [OM_DATA E_DATA V_DATA];


//champ1(xlist,ylist,...,...);
//matplot ?


