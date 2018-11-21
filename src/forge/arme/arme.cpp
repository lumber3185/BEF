#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "arme.h"

arme :: arme(){
	entite("arme", -1);
	portee = 0;
};

arme :: arme(int p) {
	entite("arme", -1);
	portee = p;
};

arme :: arme(int p, int f){
	entite("arme", f);
	portee = p;
};

arme :: ~arme() {};

int arme :: getPortee() { return portee; };
