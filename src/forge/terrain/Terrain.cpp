using namespace std;

#include "Terrain.h"
#include "../entite/entite.h"
#include "../arme/arme.h"
#include "../obstacle/obstacle.h"

Terrain::Terrain(int x = 0, int y = 0): SizeX(x), SizeY(y) {
	for(int i = 0; i < SizeX; i++) {
		vector< shared_ptr<entite> >temp;
		for(int j = 0; j < SizeY; j++) {
			temp.push_back(shared_ptr<entite>(nullptr));
		}
		grille.push_back(temp);
	}
};

Terrain::~Terrain() {};

int Terrain::getX(){ return SizeX; };

int Terrain::getY(){ return SizeY; };

void Terrain::retireEntite(int i, int j) {
	if(i < SizeX && i > 0 && j < SizeY && j > 0) {
		grille[i][j].reset();
	}
};

shared_ptr<entite> Terrain::getEntite(int x, int y) {
	return grille[x][y];
};

ostream& operator<<(ostream& flux, Terrain &t) {
	flux << "Dimensions du terrain : " << t.SizeX << ", " << t.SizeY << "." << endl;
	for(int i = 0; i < t.grille.size(); i++) {
		for(int j = 0; j < t.grille[i].size(); j++) {
			if(t.grille[i][j] != nullptr)
				flux << t.grille[i][j]->getType() << " aux coordonnées : " << i << ", " << j << "." << endl;
		}
	}
	return flux;
};
