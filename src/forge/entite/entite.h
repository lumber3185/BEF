#ifndef entite_h
#define entite_h

#include <iostream>
#include <string.h>

using namespace std;

class entite {
	protected:
		int force;
		string type;
	public:
		entite();
		entite(int f);
		entite(string t, int f);
		~entite();
		void subirDegats();
		int getForce();
		string getType();
		void setType(string t);
		void setForce(int f);
};

#endif
