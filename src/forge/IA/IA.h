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