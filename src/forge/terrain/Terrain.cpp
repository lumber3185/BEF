#include <iostream>
#include <string.h>

using namespace std;

#include "Terrain.h"
#include "../entite/entite.h"
#include "../arme/arme.h"
#include "../obstacle/obstacle.h"

Terrain::Terrain(): SizeX(0), SizeY(0), grille(NULL) {};

Terrain::Terrain(int x, int y): SizeX(x), SizeY(y), grille(NULL)  {};

Terrain::~Terrain(){
	for(int i = 0; i < SizeX; i++){
		for(int j = 0; j < SizeX; j++){
			delete[] grille[i][j];
		}
	}
};

entite& Terrain :: getEntite(int i, int j){ return *grille[i][j]; };

int Terrain :: getX(){ return SizeX; };

int Terrain :: getY(){ return SizeY; };

void Terrain :: ajoutObstacle(obstacle &e, int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0) {
		retireEntite(i,j);
		grille[i][j] = new obstacle(e);
	}
};

void Terrain :: retireEntite(int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0) {
		delete grille[i][j];
		grille[i][j] = NULL;
	}
};

ostream& operator<<(ostream& flux, Terrain& t){
	int cptsol = 0;
	for(int i = 0; i < t.getX(); i++){
		for(int j = 0; j < t.getY(); j++){
			if(t.getEntite(i,j).getForce() != 0){
				flux << i << " " << j << " " << t.getEntite(i,j).getForce() << " " << t.getEntite(i,j).getType() << "\n";
			}
			else cptsol++;
		}
	}
	if(cptsol == t.getX() * t.getY()) flux << "Terrain n'a pas d'objet \n"; 
	return flux;
};
