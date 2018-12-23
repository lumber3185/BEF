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
    cout << "load terrain \n";
    ifstream fichier(path, ios::in);
    if(fichier){
        if(type == "terrain"){
            int Taillex, Tailley;
            cout << "fichier ouvert \n";
            fichier >> Taillex >> Tailley;
            cout << Taillex << " " << Tailley << endl;
            if(Taillex == tm.getX() && Tailley == tm.getY()){
                Terrain t(Taillex, Tailley);
                cout << t;
                while(!fichier.eof()){
                    int posX, posY;
                    string typeEntite, sousType;
                    fichier >> posX >> posY >> typeEntite >> sousType;
                    cout << posX << " " << posY << " " << typeEntite << " " << sousType << endl;
                    if(typeEntite == "obstacle"){
                        t.ajoutEntite(loadObstacle(sousType), posX, posY);
                    }
                    else if(typeEntite == "arme"){
                        t.ajoutEntite(loadArme(sousType), posX, posY);
                    }
                }
            }
            else cerr << "trying to load a terrain in an other terrain of a different size";
        }
        else cerr << "trying to load a terrain with a manager not type terrain \n";
        fichier.close();
        cout << "closed \n";
    }
    else cerr << "Not a filename to a saved 'terrain'\n";
}

obstacle& FileManager::loadObstacle(string efilename){
    cout << "loadEntity" << endl;
    string chemin = "./res/sav/obstacle/" + efilename + ".txt";
    cout << chemin << endl;
    ifstream fichier(chemin);
    if(fichier){
        string t; int f;
        fichier >> t >> f;
        cout << t << f << endl;
        // statique car sinon à l'issue de la fonction la reference vers o n'existe plus et erreur de segmentation lors de l'ajout de l'obstacle
        // statique permet d'acceder à l'objet jusqu'à la fin du programme
        static obstacle o(t,f);
        return o;
    }
    else cerr << "Not a filename to an entity\n";    
}

arme& FileManager::loadArme(string efilename){
    cout << "loadEntity" << endl;
    string chemin = "./res/sav/arme/" + efilename + ".txt";
    cout << chemin << endl;
    ifstream fichier(chemin);
    if(fichier){
        string t; int p,f;
        fichier >> t >> p >> f;
        cout << t << p << f << endl;
        // statique car sinon à l'issue de la fonction la reference vers o n'existe plus et erreur de segmentation lors de l'ajout de l'obstacle
        // statique permet d'acceder à l'objet jusqu'à la fin du programme
        static arme a(t,p,f);
        return a;
    }
    else cerr << "Not a filename to an entity\n";    
}