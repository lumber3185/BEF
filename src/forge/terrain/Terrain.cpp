#include <iostream>
#include <string.h>

using namespace std;

#include "Terrain.h"
#include "../entite/entite.h"
#include "../arme/arme.h"
#include "../obstacle/obstacle.h"

Terrain::Terrain() {
	SizeX = SizeY = 0;
};

Terrain::Terrain(int x, int y) {
	SizeX = x; SizeY = y;
	
	// allocation dynamique
	grille = new contenu * [x];
	for(int i = 0; i < x; i++){
		grille[i] = new contenu[y];
	}
};

Terrain::~Terrain(){
	for(int i = 0; i < SizeX; i++){
		delete[] grille[i];
	}
};

entite& Terrain :: getObst(int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0 && grille[i][j].occupied) return grille[i][j].obst;
};

entite& Terrain :: getArme(int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0 && grille [i][j].occupied) return grille[i][j].weapon;
};

int Terrain :: getX(){ return SizeX; };
int Terrain :: getY(){ return SizeY; };

void Terrain :: ajoutObstacle(obstacle& o, int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0 && grille[i][j].occupied == 0) {
		grille[i][j].obst = o;
		grille[i][j].occupied = 1;
	}
};

void Terrain :: retireObstacle(int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0 && grille[i][j].occupied == 1) {
		grille[i][j].obst.setForce(0);
		grille[i][j].obst.setType("");
		grille[i][j].occupied = 0;
	}
};

void Terrain :: ajoutArme(arme& a, int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0 && grille[i][j].occupied == 0) {
		grille[i][j].weapon = a;
		grille[i][j].occupied = 1;
	}
};

void Terrain :: retireArme(int i, int j){
	if(i < SizeX && i > 0 && j < SizeY && j > 0 && grille[i][j].occupied == 1) {
		grille[i][j].weapon.setForce(0);
		grille[i][j].weapon.setType("");
		grille[i][j].occupied = 0;
	}
}

ostream& operator<<(ostream& flux, Terrain& t){
	int cptsol = 0;
	cout << "Caractéristiques du terrain -affiche tous les objets comme s'ils étaient des obstacles voir Terrain.h pour explication du probleme \n \non a progressé je vous jure lol \n\n";
	flux << "Dimensions " << t.SizeX << " " << t.SizeY << endl << "Liste d'objets : \n";
	for(int i = 0; i < t.getX(); i++){
		for(int j = 0; j < t.getY(); j++){
			if(t.grille[i][j].occupied != 0){
				flux << i << " " << j << " " << t.getObst(i,j).getForce() << " " << t.getObst(i,j).getType() << "\n";
			}
			else cptsol++;
		}
	}
	if(cptsol == t.getX() * t.getY()) flux << "Terrain n'a pas d'objet \n"; 
	return flux;
};
