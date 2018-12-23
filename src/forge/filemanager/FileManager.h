#ifndef FileManager_h
#define FileManager_h

#include <iostream>
#include <fstream>
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

		// ouvre un fichier en lecture et renvoit le terrain correspondant
		void loadTerrain(Terrain& t);
		
		// crée un fichier savname correspondant à t, si fichier existant, écrase le fichier existant
		void saveTerrain(Terrain T, string savname);

		// crée une entité correspondant au fichier en argument
		obstacle& loadObstacle(string entitypath);

		arme& loadArme(string efilename);
};

#endif
