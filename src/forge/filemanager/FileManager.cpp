#include <iostream>
#include <string.h>
#include <fstream>
#include <exception>

using namespace std;

#include "FileManager.h"
#include "../terrain/Terrain.h"
#include "../entite/entite.h"

FileManager::FileManager(string FileName, string t) : name(FileName), type(t) {
    if(type == "terrain" || type == "obstacle"){
        path = "./res/sav/" + type +"/" + FileName + ".txt";
    }
    else cerr << "Entrez un type de fichier valide : terrain, obstacle \n";
};

FileManager::~FileManager() {};

string FileManager::getName() { return name; };

// loader un terrain de taille correspondante au terrain à qui il sera affecté sinson exception d'index
void FileManager::loadTerrain(Terrain& tm){
    ifstream fichier(path, ios::in);
    if(fichier){
        if(type == "terrain"){
            int Taillex, Tailley;
            fichier >> Taillex >> Tailley;
            if(Taillex == tm.getX() && Tailley == tm.getY()){
                string typeEntite, sousType;
                while(!fichier.eof()){
                    int posX, posY;
                    fichier >> posX >> posY >> typeEntite >> sousType;
                    if(typeEntite == "obstacle"){
                        try{
                            tm.ajoutEntite(loadObstacle(sousType), posX, posY);
                        }
                        catch(const char* msg){
                            cerr << msg << endl;
                        }
                    }
                    else if(typeEntite == "arme"){
                        try{
                            tm.ajoutEntite(loadArme(sousType), posX, posY);
                        }
                        catch(const char* msg){
                            cerr << msg << endl;
                        }
                    }
                    typeEntite = "";
                    sousType = "";
                }
            }
            else throw "trying to load a terrain into another terrain of a different size";
        }
        else throw "trying to load a terrain with a manager not of type terrain \n";
        fichier.close();
        cout << "closed \n";
    }
    else throw "Not a filename to a saved 'terrain'\n";
}

obstacle& FileManager::loadObstacle(string efilename){
    path = "./res/sav/obstacle/" + efilename + ".txt";
    ifstream fichier(path);
    if(fichier){
        string t; int f;
        fichier >> t >> f;
        obstacle* o = new obstacle(t,f);
        return *o;
    }
    else throw "FileName Incorrect";
}

arme& FileManager::loadArme(string efilename){
    path = "./res/sav/arme/" + efilename + ".txt";
    ifstream fichier(path);
    if(fichier){
        string t; int p,f;
        fichier >> t >> p >> f;
        arme* a = new arme(t,p,f);
        return *a;
    }
    else throw "FileName Incorrect";
}

shared_ptr<entite> FileManager::loadEntity(string entityname){
    shared_ptr<entite> ret; 
    if(entityname == "bazooka" || entityname == "pistolet"){
        ret.reset(new arme(loadArme(entityname)));
    }
    else if(entityname == "petitarbre" || entityname == "grosarbre" || entityname == "petitrocher" || entityname == "grosrocher"){
        ret.reset(new obstacle(loadObstacle(entityname)));
    }
    return ret;
}

void FileManager::saveTerrain(Terrain T, string savname){
    string nomdesav = savname + ".txt";
    path = "./res/sav/terrain/" + nomdesav;
    ofstream save(path);
    string type;

    if(save){
        save << T.getX() << " " << T.getY() << endl;
        for(int i = 0; i < T.getX(); i++){
            for(int j = 0; j < T.getY(); j++){
                if(T.getEntite(i,j) != nullptr){
                    type = T.getEntite(i,j)->getType();
                    if(type == "pistolet" || type == "bazooka"){
                        save << i << " " << j << " arme " << type << endl;
                    }
                    else{
                        save << i << " " << j << " obstacle " << type << endl;
                    }
                }
            }
        }
    }
}
