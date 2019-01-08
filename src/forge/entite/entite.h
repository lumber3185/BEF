//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#ifndef entite_h
#define entite_h

#include <iostream>
#include <string.h>

using namespace std;

class entite {
	protected:
		// classe mère de Obstacle, Arme et personnage
		// type peut correspondre à personnage, pistolet, grosrocher, petitarbre...
		string type;

		// force correspond a la vie d'un obstacle lorsque la force vaut 0 l'obstacle disparait
		int force, portee;

	public:
		entite(string t = "", int f = 0, int p = 0);
		
		~entite();
		
		int getForce();
		
		int getPortee();
		
		string getType();
		
		void setType(string t);
		
		void setForce(int f);
		
		friend ostream& operator<<(ostream& flux, entite& e);
};

#endif
