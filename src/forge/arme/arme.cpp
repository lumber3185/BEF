#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "arme.h"

arme :: arme(){
	type = "arme";
	force = -1;
	portee = 0;
};

arme :: arme(int p) {
	type = "arme";
	force = -1;
	portee = p;
};

arme :: arme(int p, int f){
	type = "arme";
	force = f;
	portee = p;
};

arme :: ~arme() {};

int arme :: getPortee() { return portee; };
