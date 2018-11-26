#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "obstacle.h"

obstacle :: obstacle() {
	type = "obstacle";
	force = 0;
	typeObst = "";
};

obstacle :: obstacle(string TObst) {
	type = "obstacle";
	typeObst = TObst;
};

obstacle :: obstacle(string TypeObst, int f){
	type = "obstacle";
	force = f;
	typeObst = TypeObst;
}

obstacle :: ~obstacle() {};

string obstacle :: getTypeObst() { return typeObst; };
string obstacle :: getType() { return type;}