#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "obstacle.h"

obstacle :: obstacle() {
	entite("obstacle", -1);
	typeObst = "";
};

obstacle :: obstacle(string TypeObst) {
	entite("obstacle", -1);
	typeObst = "";
};

obstacle :: obstacle(string TypeObst, int f){
	entite("obstacle", f);
	typeObst = TypeObst;
}

obstacle :: ~obstacle() {};

string obstacle :: getTypeObst() { return typeObst; };
