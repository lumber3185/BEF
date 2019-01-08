//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#ifndef terrain_h
#define terrain_h

#include <iostream>
#include <string.h>
#include <vector>
#include <memory>

#include "../entite/entite.h" 
#include "../obstacle/obstacle.h"
#include "../arme/arme.h"

using namespace std;

class Terrain {
	private:
		int SizeX, SizeY;
		vector< vector< shared_ptr<entite> > > grille;
	public:

		template<class T>
		void ajoutEntite(T& nouv, int i, int j) {
			if(i < SizeX && i > 0 && j < SizeY && j > 0) {
				grille[i][j].reset(new T(nouv));
			}
		};

		shared_ptr<entite> getEntite(int x, int y);

		Terrain(int SizeX, int SizeY);
		~Terrain();
		void retireEntite(int x, int y);
		int getX();
		int getY();
		friend ostream& operator<<(ostream& flux, Terrain& t);
};

#endif
