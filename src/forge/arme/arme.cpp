#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "arme.h"

arme :: arme(string t = "arme", int p = 0, int f = -1): entite(t, f), portee(p) {};

arme::arme(arme &copie): entite(copie.getType(), copie.getForce()), portee(copie.getPortee()) {};

arme::~arme() {};

int arme::getPortee() { return portee; };
