#include <iostream>
#include <string.h>

using namespace std;

#include "obstacle.h"

obstacle :: obstacle() : type("none yet") {};
obstacle :: obstacle(string t) : type(t) {};
obstacle :: ~obstacle() {};

string obstacle :: getType() { return type; };
