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
		Terrain(int SizeX, int SizeY);
		~Terrain();
		void ajoutObstacle(obstacle& obst, int x, int y);
		void retireEntite(int x, int y);
		entite& getEntite(int x, int y);
		int getX();
		int getY();
		friend ostream& operator<<(ostream& flux, Terrain& t);
};

#endif
