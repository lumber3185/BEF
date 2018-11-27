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
