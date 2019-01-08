//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
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
