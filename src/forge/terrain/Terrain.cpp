#include <iostream>
#include <string.h>

using namespace std;

#include "Terrain.h"
#include "../entite/entite.h"
#include "../arme/arme.h"
#include "../obstacle/obstacle.h"

Terrain::Terrain() {
	this->SizeX = 0; this->SizeY = 0;
	this->grille = NULL;
};

Terrain::Terrain(int x, int y) {
	SizeX = x; SizeY = y;
	
	// allocation dynamique
	grille = new entite * [x];
	for(int i = 0; i < x; i++){
		grille[i] = new entite[y];
	}
	
	// tous les objets sont des entités de force 0 -> sol
	entite e(0);
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			grille[i][j] = e;
		}
	}
};

Terrain::~Terrain(){
	for(int i = 0; i < SizeX; i++){
		delete[] grille[i];
	}
};

entite& Terrain :: getObst(int i, int j){
	return grille[i][j];
};

int Terrain :: getX(){ return SizeX; };
int Terrain :: getY(){ return SizeY; };

void Terrain :: ajoutObstacle(entite& e, int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0) {
		grille[i][j] = e;
	}
};

void Terrain :: retireObstacle(int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0) grille[i][j].setForce(0);
};

ostream& operator<<(ostream& flux, Terrain& t){
	int cptsol = 0;
	for(int i = 0; i < t.getX(); i++){
		for(int j = 0; j < t.getY(); j++){
			if(t.getObst(i,j).getForce() != 0){
				flux << i << " " << j << " " << t.getObst(i,j).getForce() << " " << t.getObst(i,j).getType() << "\n";
			}
			else cptsol++;
		}
	}
	if(cptsol == t.getX() * t.getY()) flux << "Terrain n'a pas d'objet \n"; 
	return flux;
};
