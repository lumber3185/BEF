#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "obstacle.h"

obstacle :: obstacle(string TypeObst = "", int f = -1): entite("obstacle", f), typeObst(TypeObst) {};

obstacle :: obstacle(obstacle &copie): entite(copie.getType(), copie.getForce()), typeObst(copie.getTypeObst()) {};

obstacle :: ~obstacle() {};

string obstacle :: getTypeObst() { return typeObst; };
