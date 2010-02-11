// Generation du maillage d'un terrain
//  definition d'un profil et extrusion

clear

xmin = 0;
xmax = 100;
ymin = 0;
ymax = 0;

// Nb de points du maillage
Nx = 50; // nb de points en x
Ny = 50; // nb de points en y

X = [xmin:(xmax-xmin)/Nx:xmax]';
Y = [ymin:(ymax-ymin)/Ny:ymax]';
Z = [];

xlim = 40;
for i=1:Nx+1,
  x = X(i);
  if x<xlim then,
    z = 0.09 * x;
    zlim = z;
  else
    z = 0.02 * (x - xlim) + zlim;
  end
  Z = [Z ; z];
end

plot2d(X, Z, style=-1); // visu profil

// extrusion