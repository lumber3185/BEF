#include <iostream>
#include <string.h>
#include <fstream>
#include <exception>

using namespace std;

#include "FileManager.h"
#include "../terrain/Terrain.h"
#include "../entite/entite.h"

FileManager :: FileManager(string FileName, string t) : name(FileName), type(t) {
    if(type == "terrain" || type == "obstacle"){
        path = "../res/sav/" + type +"/" + FileName + ".txt";
    }
    else cerr << "Entrez un type de fichier valide : terrain, obstacle";
};

FileManager :: ~FileManager() {};

Terrain FileManager:: loadTerrain(){
    Terrain t(2,2);
    cout << path << endl;
    ifstream fichier(path, ios::in);
    if(fichier){
        fichier.close();
    }
    else cerr << "erreur ouverture \n";
    return t;
}