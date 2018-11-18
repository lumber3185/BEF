#include <iostream>
#include <string.h>

using namespace std;

#include "entite.h"

entite :: entite() : force(0) {};
entite :: entite(int f) : force(f) {};
entite :: ~entite() {};

int entite :: getForce() { return force; };
