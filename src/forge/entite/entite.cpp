#include <iostream>
#include <string.h>

using namespace std;

#include "entite.h"

entite::entite(string t, int f, int p) : type(t), force(f), portee(p) {};
entite::~entite() {};

string entite::getType() { return type; };
int entite::getForce() { return force; };
int entite::getPortee() { return portee; };
void entite::setForce(int f) { force = f; };
void entite::setType(string s) { type = s; };

ostream& operator<<(ostream& flux, entite& e){
    flux << e.type << " " << e.force;
    return flux;
};
