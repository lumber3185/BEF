#include <iostream>
#include <string.h>

using namespace std;

#include "../terrain/Terrain.h"
#include "../arme/arme.h"
#include "../entite/entite.h"
#include "personnage.h"

personnage::personnage(Terrain& t): entite("personnage", 0), a(new arme("poing", 1, 1)){
    x = rand() % t.getX();
    y = rand() % t.getY();
    mon_tour = 0;
    pdv = 15;
    orientation = nord;

    // tant qu'il y a quelque chose sur les coordonnées (x,y) on cherche un autre emplacement sur le terrain où placer le personnage
    while(t.getEntite(x, y) != nullptr){
        cout<< "un objet detecté en" << x << y << endl;
        x = rand() % t.getX();
        y = rand() % t.getY();
    }
    t.ajoutEntite(*this, x, y);
};

personnage::personnage(Terrain& t, int x, int y): entite("personnage", 0), a(new arme("poing", 1, 1)), x(x), y(y){
    pdv = 15;
    orientation = 0;
    t.ajoutEntite(*this, x, y);
    mon_tour = 0;
}

personnage::~personnage(){};

int personnage::getX(){
    return x;
};

int personnage::get_pdv(){
    return pdv;
};

int personnage::getY(){
    return y;
};

void personnage::changerOrientation(int orientation){
    this->orientation = orientation;
};

int personnage::mouv(Terrain& t){
    int deplace = 0;
    cout << "mouv";
    switch(orientation){
        case personnage::nord:
            if(t.getEntite(x,y+1) == nullptr){
                if(y+1 <= t.getY()){
                    cout << "north case" << endl;
                    t.ajoutEntite(*this, x, y+1);
                    this->y++;
                    t.retireEntite(x,y);
                    deplace = 1;
                }
                else{
                    cout << "out of bounds" << endl;
                }
            }
            else{
                cout << "impossible to move there" << endl;
            }
        break;
        case personnage::est:
            if(t.getEntite(x+1,y) == nullptr){
                if(x+1 <= t.getX()){
                    t.ajoutEntite(*this, x+1, y);
                    x++;
                    t.retireEntite(x,y);
                    deplace = 1;
                }
                            else{
                    cout << "out of bounds" << endl;
                }
            }
            else{
                cout << "impossible to move there" << endl;
            }
        break;
        case personnage::sud:
            if(t.getEntite(x,y-1) == nullptr){
                if(y-1 >= 0){
                t.ajoutEntite(*this, x, y-1);
                y--;
                t.retireEntite(x,y);
                deplace = 1;
                }
                                else{
                    cout << "out of bounds" << endl;
                }
            }
            else{
                cout << "impossible to move there" << endl;
            }
        break;
        case personnage::ouest:
            if(t.getEntite(x-1,y) == nullptr){
                if(x-1 >= 0){
                    t.ajoutEntite(*this, x-1, y);
                    x--;
                    t.retireEntite(x,y);
                    deplace = 1;
                }
                            else{
                    cout << "out of bounds" << endl;
                }
            }
            else{
                cout << "impossible to move there" << endl;
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

int personnage::tir(Terrain& t){
	for(int i=1; i <= a->getPortee(); i++) {
		switch(orientation) {
		case 0:
			if(t.getEntite(x,y+i) != nullptr) {
				t.getEntite(x,y+i)->setForce(t.getEntite(x,y+i)->getForce() - a->getForce());
				if(t.getEntite(x,y+i)->getForce() <= 0)
					t.retireEntite(x,y+i);
				return 1;
			}
			break;
		case 1:
			if(t.getEntite(x+i,y) != nullptr) {
				t.getEntite(x+i,y)->setForce(t.getEntite(x+i,y)->getForce() - a->getForce());
				if(t.getEntite(x+i,y)->getForce() <= 0)
					t.retireEntite(x+i,y);
				return 1;
			}
			break;
		case 2:
			if(t.getEntite(x,y-i) != nullptr) {
				t.getEntite(x,y-i)->setForce(t.getEntite(x,y-i)->getForce() - a->getForce());
				if(t.getEntite(x,y-i)->getForce() <= 0)
					t.retireEntite(x,y-i);
				return 1;
			}
			break;
		case 3:
			if(t.getEntite(x-i,y) != nullptr) {
				t.getEntite(x-i,y)->setForce(t.getEntite(x-i,y)->getForce() - a->getForce());
				if(t.getEntite(x-i,y)->getForce() <= 0)
					t.retireEntite(x-i,y);
				return 1;
			}
			break;
		}
	}
	return 0;
};

bool personnage::get_tour(){
    return this->mon_tour;
}

void personnage::set_tour(bool b){
    this->mon_tour = b;
}

int personnage::getOrientation(){
    return this->orientation;
}

ostream& operator<<(ostream& flux, personnage& p){
    flux << "Personnage : " << endl;
    flux << "Vie : " << p.pdv << " Orientation : " << p.orientation  << " Placement : " << p.x << " " << p.y << endl;
    flux << "Son Arme : " << p.a->getType() << endl;

    return flux;
};
