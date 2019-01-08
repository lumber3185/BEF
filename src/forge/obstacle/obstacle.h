//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#ifndef obstacle_h
#define obstacle_h

#include <string.h>

using namespace std;

#include "../entite/entite.h"

class obstacle : public entite {
	public:
		obstacle(string TypeObst, int f);
		obstacle(obstacle &copie);
		~obstacle();
};

#endif
