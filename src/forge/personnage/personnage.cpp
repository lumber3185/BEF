#include <iostream>
#include <string.h>

using namespace std;

#include "../terrain/Terrain.h"
#include "../arme/arme.h"
#include "../entite/entite.h"
#include "personnage.h"

personnage::personnage(Terrain& t, int x, int y): entite("personnage", 0), a(new arme("poing", 1, 1)), x(x), y(y){
	if(x == -1)
        x = rand() % t.getX();
	if(y == -1)
        y = rand() % t.getY();
    pdv = 15;
    orientation = 0;

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
            if(t.getEntite(x,y+1) == nullptr){
                t.ajoutEntite(*this, x, y+1);
                t.retireEntite(x,y);
                deplace = 1;
            }
        break;
        case 1:
            if(t.getEntite(x+1,y) == nullptr){
                t.ajoutEntite(*this, x+1, y);
                t.retireEntite(x,y);
                deplace = 1;
            }
        break;
        case 2:
            if(t.getEntite(x,y-1) == nullptr){
                t.ajoutEntite(*this, x, y-1);
                t.retireEntite(x,y);
                deplace = 1;
            }
        break;
        case 3:
            if(t.getEntite(x-1,y) == nullptr){
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
	            	arme* ramasse = new arme();
	            	ramasse->setForce(t.getEntite(x,y+1)->getForce());
	            	ramasse->setType(t.getEntite(x,y+1)->getType());
	            	ramasse->setPortee(t.getEntite(x,y+1)->getPortee());
					a.reset(ramasse);
					t.retireEntite(x, y+1);
					return 1;
				}
			}
			break;
        case 1:
        	if(t.getEntite(x+1, y) != nullptr){
        	            if(t.getEntite(x+1, y)->getType() == "pistolet" || t.getEntite(x+1, y)->getType() == "bazooka"){
        	            	arme* ramasse = new arme();
        	            	ramasse->setForce(t.getEntite(x+1,y)->getForce());
        	            	ramasse->setType(t.getEntite(x+1,y)->getType());
        	            	ramasse->setPortee(t.getEntite(x+1,y)->getPortee());
        	                a.reset(ramasse);
        	                t.retireEntite(x+1,y);
        	                return 1;
        	            }
        	        }
        	break;
        case 2:
        	if(t.getEntite(x, y-1) != nullptr){
        	            if(t.getEntite(x, y-1)->getType() == "pistolet" || t.getEntite(x, y-1)->getType() == "bazooka"){
        	            	arme* ramasse = new arme();
        	            	ramasse->setForce(t.getEntite(x,y-1)->getForce());
        	            	ramasse->setType(t.getEntite(x,y-1)->getType());
        	            	ramasse->setPortee(t.getEntite(x,y-1)->getPortee());
        	                a.reset(ramasse);
        	                t.retireEntite(x, y-1);
        	                return 1;
        	            }
        	        }
        	break;
        case 3:
        	if(t.getEntite(x-1, y) != nullptr){
        	            if(t.getEntite(x-1, y)->getType() == "pistolet" || t.getEntite(x-1, y)->getType() == "bazooka"){
        	            	arme* ramasse = new arme();
        	            	ramasse->setForce(t.getEntite(x-1,y)->getForce());
        	            	ramasse->setType(t.getEntite(x-1,y)->getType());
        	            	ramasse->setPortee(t.getEntite(x-1,y)->getPortee());
        	                a.reset(ramasse);
        	                t.retireEntite(x-1,y);
        	                return 1;
        	            }
        	        }
        	break;
    }
    return 0;
};

void personnage::tir(Terrain& t, int angle){

};

ostream& operator<<(ostream& flux, personnage& p){
    flux << "Personnage : " << endl;
    flux << "Vie : " << p.pdv << " Orientation : " << p.orientation  << " Placement : " << p.x << " " << p.y << endl;
    flux << "Son Arme : " << p.a->getType() << endl;

    return flux;
};
