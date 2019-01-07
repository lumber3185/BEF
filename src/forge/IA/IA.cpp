#include <iostream>

using namespace std;

#include "../terrain/Terrain.h"
#include "../personnage/personnage.h"
#include "../IA/IA.h"

IA::IA(Terrain& t):personnage(t){};
IA::~IA(){};


// intelligence artificielle très pourrie
void IA::mouvance(Terrain& t){
    int aleaturn = rand() % 8;
    int aleamouv = rand() % 2;
    int aleatir = rand() % 2;

    // 4 chances sur 8 de tourner
    if(aleaturn < 4){
        changerOrientation(aleaturn);
        mouv(t);
    }
    else{}

    // 1 chance sur 2 de bouger
    if(aleamouv){
        mouv(t);
    }
    else{}

    // 1 chance sur 2 de tirer
    if(aleatir){
        tir(t, 45);
    }

};
