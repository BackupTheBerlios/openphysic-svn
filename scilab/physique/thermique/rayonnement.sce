// Etude numérique du rayonnement d'un corps noir

clear

h = 6.6256e-34; 
c0 = 2.9979e8; 
kB = 1.3807e-23;

function E = corpsnoir(lambda,T)
  // E = corpsnoir(lambda,T)
  
  // calcule la densite d'energie associee a un corps noir
  // qui est porte a une temperature T
  //   lambda   longueur d'onde [m]  (vecteur)
  //   T   temperature [K] (scalaire)
  //   E   intensite
  
  E = 8*%pi*h*c0./(lambda.^5)./ (exp(h*c0./(kB*T*lambda))-1);
endfunction

lambda = [1E-10:0.01E-6:2E-6];
T = 10000; // temperature (K)

phi_lambda = corpsnoir(lambda,T);

clf

plot2d(lambda,phi_lambda)

[phi_lambda_max,nmax] = max(phi_lambda);
lambda_max = lambda(nmax);

// Loi du déplacement de Wien : lambda_max*T=sigma_w
lambda_max*T
sigma_w = 2.898768651*10^(-3) // constante de Wien m.K
eps=abs(sigma_w-lambda_max*T)/sigma_w*100

// M=sigma*T^4
