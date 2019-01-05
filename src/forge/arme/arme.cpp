#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "arme.h"

arme::arme(string t, int p, int f): entite(t, f), portee(p) {};

arme::arme(arme &copie): entite(copie.getType(), copie.getForce()), portee(copie.getPortee()) {};

arme::~arme() {};

int arme::getPortee() { return portee; };

void arme::setPortee(int p) { this->portee = p; };
