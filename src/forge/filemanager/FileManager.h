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
		FileManager(string filename, string t);
		~FileManager();
		string getName();

		// ouvre un fichier en lecture et renvoit le terrain correspondant, lance exceptionz
		void loadTerrain(Terrain& t);
		
		// crée un fichier savname correspondant à t, si fichier existant, écrase le fichier existant
		void saveTerrain(Terrain T, string savname);

		// crée une entité correspondant au nom de l'entité en argument, lance des exceptions
		obstacle& loadObstacle(string entityname);

		arme& loadArme(string entityname);

		shared_ptr<entite> loadEntity(string entityname);
};

#endif
