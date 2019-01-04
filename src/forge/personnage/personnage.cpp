#include <iostream>
#include <string.h>

using namespace std;

#include "../terrain/Terrain.h"
#include "../arme/arme.h"
#include "../entite/entite.h"
#include "personnage.h"

personnage::personnage(Terrain& t): entite("personnage", 0), a(arme("poing", 1, 1)){ 
    x = rand() % t.getX();
    y = rand() % t.getY();
    pdv = 15;
    orientation = 0;

    // la force de l'entité personnage équivaut à celle de l'arme qu'il porte
    setForce(a.getForce());

    // tant qu'il y a quelque chose sur les coordonnées (x,y) on cherche un autre emplacement sur le terrain où placer le personnage
    while(t.getEntite(x, y) != nullptr){
        cout<< "un objet detecté en" << x << y << endl;
        x = rand() % t.getX();
        y = rand() % t.getY();
    }
    t.ajoutEntite(*this, x, y);
};

personnage::~personnage(){};

int personnage::getX(){
    return x;
};

int personnage::getY(){
    return y;
};

void personnage::changerOrientation(int orientation){
    this->orientation = orientation;
};

int personnage::mouv(Terrain& t){
    int deplace = 0;

    switch(orientation){
        case 0:
            if(t.getEntite(x,y+1) == NULL){
                t.ajoutEntite(*this, x, y+1);
                t.retireEntite(x,y);
                deplace = 1;
            }
        break;
        case 1:
            if(t.getEntite(x+1,y) == NULL){
                t.ajoutEntite(*this, x+1, y);
                t.retireEntite(x,y);
                deplace = 1;
            }
        break;
        case 2:
            if(t.getEntite(x,y-1) == NULL){
                t.ajoutEntite(*this, x, y-1);
                t.retireEntite(x,y);
                deplace = 1;
            }
        break;
        case 3:
            if(t.getEntite(x-1,y) == NULL){
                t.ajoutEntite(*this, x-1, y);
                t.retireEntite(x,y);
                deplace = 1;
            }
        break;
    }
    return deplace;
};

int personnage::ramasser(Terrain& t){
    switch(orientation){
        case 0:
        if(t.getEntite(x, y+1) != nullptr){
            if(t.getEntite(x, y+1)->getType() == "pistolet" || t.getEntite(x, y+1)->getType() == "bazooka"){
                //a.setType(t.getEntite(x, y+1)->getType());
                //a.setForce(t.getEntite(x,y+1)->getForce());
                t.retireEntite(x, y+1);
                return 1;
            }
        } 
        break;
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
    }
};

void personnage::tir(Terrain& t, int angle){

};

ostream& operator<<(ostream& flux, personnage& p){
    flux << "Personnage : " << endl;
    flux << "Vie : " << p.pdv << " Orientation : " << p.orientation  << " Placement : " << p.x << " " << p.y << endl;
    flux << "Son Arme : " << p.a.getType() << endl;

    return flux;
};