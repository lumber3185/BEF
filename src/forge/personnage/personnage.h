//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#ifndef personnage_h
#define personnage_h

#include "../arme/arme.h"
#include "../entite/entite.h"
#include "../terrain/Terrain.h"
#include <memory>

class personnage : public entite {
    private:
        
        shared_ptr<arme> a;
        // le personnage garde ses coordonnées, facilite les tests sur le terrain depuis joueur, sinon on aurait besoin de chercher les coordonnées du joueur à chaque fonction pour faire tests
        int x,y;
        int pdv;// défaut : 15
        bool mon_tour;
        int orientation;
    public:
        personnage(Terrain& t);
        personnage(Terrain& t, int x, int y);
        ~personnage();
        // 0 nord, 1 est, 2 sud, 3 ouest
        enum direction
        {
            nord,
            est,
            sud,
            ouest
        };
        int getX();
        int getY();
        int get_pdv();
        void set_tour(bool b);
        bool get_tour();
        int getOrientation();
        void changerOrientation(int orientation);
        int tir(Terrain& t);
        // 1 si le personnage a réussi à bouger, 0 sinon
        int mouv(Terrain& t);

        // 1 si le personnage a reussi à ramasser l'arme, 0 sinon
        int ramasser(Terrain& t);

        friend ostream& operator<<(ostream& flux, personnage& p);
};

#endif
