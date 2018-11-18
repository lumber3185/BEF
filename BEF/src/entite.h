#ifndef entite_h
#define entite_h

#include <iostream>
#include <string.h>

using namespace std;

class entite {
	protected:
		int force;
	public:
		entite();
		entite(int f);
		~entite();
		void subirDegats();
		int getForce();
};

#endif
