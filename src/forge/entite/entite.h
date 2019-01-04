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
		entite(string t, int f);
		~entite();
		void subirDegats();
		int getForce();
		string getType();
		void setType(string t);
		void setForce(int f);
		friend ostream& operator<<(ostream& flux, entite& e);
};

#endif
