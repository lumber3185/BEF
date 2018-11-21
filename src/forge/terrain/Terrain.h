#ifndef terrain_h
#define terrain_h

#include <iostream>
#include <string.h>

#include "../entite/entite.h" 
#include "../obstacle/obstacle.h"
#include "../arme/arme.h"

using namespace std;


// tout objet à force 0 est considéré comme du sol
class Terrain {
	private:
		int SizeX, SizeY;
		entite** grille;
	public:
		Terrain();
		// initialise la grille comme une matrice d'entités de force 0 -> sol
		Terrain(int SizeX, int SizeY);
		~Terrain();
		void ajoutObstacle(entite& obst, int x, int y);
		void retireObstacle(int x, int y);
		entite& getObst(int x, int y);
		int getX();
		int getY();
		friend ostream& operator<<(ostream& flux, Terrain& t);
};

#endif
