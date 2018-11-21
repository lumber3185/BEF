#include <iostream>
#include <string.h>

using namespace std;

#include "entite.h"

entite :: entite() : force(0) {};
entite :: entite(int f) : force(f) {};
entite :: entite(string t, int f) : force(f), type(t){};
entite :: ~entite() {};

string entite :: getType() { return type; };
int entite :: getForce() { return force; };
void entite :: setForce(int f) { force = f; };

