//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#include <iostream>
#include <string.h>

using namespace std;

#include "../entite/entite.h"
#include "obstacle.h"

obstacle::obstacle(string t = "obstacle", int f = -1): entite(t, f) {};

obstacle::obstacle(obstacle &copie): entite(copie.getType(), copie.getForce()) {};

obstacle::~obstacle() {};
