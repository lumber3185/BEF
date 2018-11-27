#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "arme.h"

arme :: arme(int p = 0, int f = -1): entite("arme", f), portee(p) {};

arme :: ~arme() {};

int arme :: getPortee() { return portee; };
