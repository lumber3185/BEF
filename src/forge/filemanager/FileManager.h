//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#ifndef FileManager_h
#define FileManager_h

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string.h>

using namespace std;

#include "../terrain/Terrain.h"
#include "../entite/entite.h"

class FileManager {
	private:
		string path;
		string name;
		string type;

	public:

		// crée un filemanager qui gère un fichier denom filename et de type t(terrain, entite, obstacle, arme...)
		FileManager(string filename, string t);
		
		~FileManager();

		// renvoie le nom du fichier que gère le filemanager
		string getName();

		// ouvre un fichier en lecture et renvoit le terrain correspondant, lance une exception si une erreur a lieu
		void loadTerrain(Terrain& t);
		
		// crée un fichier de nom 'savname' correspondant à t, si fichier existant, écrase le fichier existant
		void saveTerrain(Terrain T, string savname);

		// Cherche dans le dossier res/sav/obstacle l'obstacle en argument et le retourne
		obstacle& loadObstacle(string entityname);

		// Cherche dans le dossier res/sav/arme l'arme en argument et la retourne
		arme& loadArme(string entityname);

		// retourne un pointeur correspondant au nom de l'entité en argument, utilise les méthodes loadArme et loadObstacle
		shared_ptr<entite> loadEntity(string entityname);
};

#endif
