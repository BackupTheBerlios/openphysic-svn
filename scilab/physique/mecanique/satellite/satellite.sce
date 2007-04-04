// Mouvement d'un satellite
// Sebastien CELLES
// ToDo : resolution de l'equa diff (vectorielle) avec ode

clear;

G = 6.67E-11; // USI // constante

Mterre = 5.9736E24; // kg // masse de la Terre

// temps
t0 = 0;
t = [t0:60:t0+3600*24];


// Planète A
mA = Mterre; // kg // masse du point A
OA_0 = [0 0 0]; // m // position du point A
vA_0 = [0 0 0]; // m/s // vitesse du point A

// Satellite B
mB = 1E3; // kg masse du point B

d_sat_geo = 35786E3; // m // 36000km = distance Terre-Sat pour sat geostationnaire
v_sat_geo = 3.07E3; // m/s // vitesse sat geostationnaire

OB_0 = [0 d_sat_geo 0]; // position du point B
vB_0 = [v_sat_geo 0 0]; // m/s // vitesse du point B

// init A
OA = OA_0;
//vA = vA_0;

// init B
OB = OB_0;
vB = vB_0;

AB = OB - OA; // \vect{AB}
uAB = AB / norm(AB); // vecteur uniteur de A vers B

F_AB = - G * (mA * mB) * uAB / (norm(AB)^2);
//F_AB = - G * (mA * mB) * AB / (norm(AB)^3);

F_BA = - F_AB;

ETAT_A_0 = [OA_0 ; vA_0];
ETAT_B_0 = [OB_0 ; vB_0];

// init ETAT
ETAT_A = ETAT_A_0;
ETAT_B = ETAT_B_0;

// F = m * a => a = F/m
// F = m * v.
// OB. = vB

function [f]=MonSecondMembre(t,ETAT)
  f(1,:) = ETAT(2,:); // (:,2) or (2,:)
  f(2,:) = F_AB/mB;
endfunction

ETAT_B = ode(ETAT_B_0,t0,t,MonSecondMembre);
POS_B = ETAT_B(1,:);

