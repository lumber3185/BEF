#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "obstacle.h"

obstacle::obstacle(string t = "obstacle", int f = -1): entite(t, f) {};

obstacle::obstacle(obstacle &copie): entite(copie.getType(), copie.getForce()) {};

obstacle::~obstacle() {};
