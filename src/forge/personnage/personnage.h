#ifndef personnage_h
#define personnage_h

#include "../arme/arme.h"
#include "../entite/entite.h"
#include "../terrain/Terrain.h"
#include <memory>

class personnage : public entite {
    private:
        // le personnage garde ses coordonnées, facilite les tests sur le terrain depuis joueur, sinon on aurait besoin de chercher les coordonnées du joueur à chaque fonction pour faire tests
        int x,y;
        // défaut : 15
        int pdv;
        // 0 nord, 1 est, 2 sud, 3 ouest
        int orientation;
        // défaut : "poing", force = 1, portée=1
        shared_ptr<arme> a;
    public:
        personnage(Terrain& t);
        personnage(Terrain& t, int x, int y);
        ~personnage();
        int getX();
        int getY();
        void changerOrientation(int orientation);
        void tir(Terrain& t, int angle);

        // 1 si le personnage a réussi à bouger, 0 sinon
        int mouv(Terrain& t);

        // 1 si le personnage a reussi à ramasser l'arme, 0 sinon
        int ramasser(Terrain& t);

        friend ostream& operator<<(ostream& flux, personnage& p);
};

#endif
