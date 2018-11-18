#ifndef terrain_h
#define terrain_h

#include <iostream>
#include <string.h>

#include "../entite/entite.h" 
#include "../obstacle/obstacle.h"
#include "../arme/arme.h"

using namespace std;

class Terrain {
	private:
		int SizeX, SizeY;
		entite** grille;
	public:
		Terrain();
		Terrain(int SizeX, int SizeY);
		~Terrain();
		void MAJ();
		void ajoutObstacle(entite obst, int x, int y);
		void retireObstacle(int x, int y);
		int getObst(int x, int y);
};

#endif
