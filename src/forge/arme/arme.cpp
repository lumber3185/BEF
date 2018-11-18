#include <iostream>
#include <string.h>

using namespace std;

#include "arme.h"

arme :: arme() : portee(0) {};
arme :: arme(int p) : portee(p) {};
arme :: ~arme() {};

int arme :: getPortee() { return portee; };
