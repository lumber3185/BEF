#ifndef personnage_h
#define personnage_h

#include "../arme/arme.h"
#include "../entite/entite.h"
#include "../terrain/Terrain.h"

class personnage : public entite {
    private:
        // le personnage garde ses coordonnées, facilite les tests sur le terrain depuis joueur, sinon on aurait besoin de chercher les coordonnées du joueur à chaque fonction pour faire tests
        int x,y;
        // défaut : 15
        int pdv;
        // 0 nord, 1 est, 2 sud, 3 ouest
        int orientation;
        // défaut : "poing", force = 1, portée=1
        arme a;
    public:
        personnage(Terrain& t);
        ~personnage();
        int getX();
        int getY();
        void changerOrientation(int orientation);
        void tir(Terrain& t);
        // 1 si réussi, 0 sinon
        int mouv(Terrain& t);
        friend ostream& operator<<(ostream& flux, personnage& p);
};

#endif