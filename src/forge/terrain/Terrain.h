#ifndef terrain_h
#define terrain_h

#include <iostream>
#include <string.h>

#include "../entite/entite.h" 
#include "../obstacle/obstacle.h"
#include "../arme/arme.h"

using namespace std;


// attention code ne répond pas exactement au besoin, occupied ne nous dit pas en l'état actuel du code par quoi la case est occupée
// problématique pour vérifier si getObst peut bien renvoyer un obstacle par ex
// meme probleme pour l'affichage ou pour tout retour du contenu de grille[i][j]
// mettre un string a la place d'un int?

struct contenu{
	int occupied = 0;
	arme weapon;
	obstacle obst;
};

class Terrain {
	private:
		int SizeX, SizeY;
		contenu** grille;
	public:
		Terrain();
		Terrain(int SizeX, int SizeY);
		~Terrain();
		void ajoutObstacle(obstacle& obst, int x, int y);
		void ajoutArme(arme& a, int x, int y);
		void retireObstacle(int x, int y);
		void retireArme(int x, int y);
		entite& getObst(int x, int y);
		entite& getArme(int x, int y);
		int getX();
		int getY();
		friend ostream& operator<<(ostream& flux, Terrain& t);
};

#endif
