#include <iostream>
#include <string.h>

using namespace std;

#include "entite.h"

entite::entite(string t = "", int f = 0) : type(t), force(f) {};
entite::~entite() {};

string entite::getType() { return type; };
int entite::getForce() { return force; };
int entite::getPortee() { return -1; };
void entite::setForce(int f) { force = f; };
void entite::setType(string s) { type = s; };

ostream& operator<<(ostream& flux, entite& e){
    flux << e.type << " " << e.force;
    return flux;
};
