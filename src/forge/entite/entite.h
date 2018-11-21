#ifndef entite_h
#define entite_h

#include <iostream>
#include <string.h>

using namespace std;

class entite {
	protected:
	// si la force est de 0, l'entité est une entité nulle on a affaire à du sol
		int force;
		string type = "entite";
	public:
		entite();
		entite(int f);
		entite(string t, int f);
		~entite();
		void subirDegats();
		int getForce();
		string getType();
		void setForce(int f);
};

#endif
