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

Terrain::~Terrain(){
	for(int i = 0; i < SizeX; i++){
		for(int j = 0; j < SizeX; j++){
			grille.pop_back();
		}
	}
};

entite& Terrain :: getEntite(int i, int j){ return *grille[i][j]; };

int Terrain :: getX(){ return SizeX; };

int Terrain :: getY(){ return SizeY; };

void Terrain :: ajoutObstacle(obstacle &e, int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0) {
		grille[i][j].reset(new obstacle(e));
	}
};

void Terrain :: retireEntite(int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0) {
		grille[i][j].reset();
	}
};

ostream& operator<<(ostream& flux, Terrain &t){
	for(int i = 0; i < t.grille.size(); i++) {
		for(int j = 0; j < t.grille[i].size(); j++) {
			if(t.grille[i][j] != nullptr)
				cout << t.grille[i][j]->getType();
		}
		cout << endl;
	}
	return flux;
};
