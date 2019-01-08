//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "arme.h"

arme::arme(string t, int p, int f): entite(t, f, p) {};

arme::arme(arme &copie): entite(copie.getType(), copie.getForce(), copie.getPortee()) {};

arme::~arme() {};

void arme::setPortee(int p) { this->portee = p; };
