#ifndef obstacle_h
#define obstacle_h

#include <string.h>

using namespace std;

#include "entite.h"

class obstacle : public entite {
	private:
		string type;
	public:
		obstacle();
		obstacle(string t);
		~obstacle();
		string getType();
};

#endif
