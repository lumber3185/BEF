//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#ifndef IA_h
#define IA_h

using namespace std;

#include "../personnage/personnage.h"
#include "../arme/arme.h"
#include "../terrain/Terrain.h"

class IA : public personnage {
    public:
        IA(Terrain& t);
        ~IA();
        void mouvance(Terrain& t);
};

#endif
