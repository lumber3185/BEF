#ifndef entite_h
#define entite_h

#include <iostream>
#include <string.h>

using namespace std;

class entite {
	protected:
		int force;
		string type = "entite";
	public:
		entite(string t, int f);
		~entite();
		void subirDegats();
		int getForce();
		string getType();
		void setForce(int f);
};

#endif