#ifndef obstacle_h
#define obstacle_h

#include <string.h>

using namespace std;

#include "../entite/entite.h"

class obstacle : public entite {
	private:
		string typeObst;
	public:
		obstacle();
		obstacle(string TypeObst);
		obstacle(string TypeObst, int f);
		~obstacle();
		string getTypeObst();
		string getType();
};

#endif
