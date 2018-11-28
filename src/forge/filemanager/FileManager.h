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
		Terrain loadTerrain();
		void saveTerrain(Terrain T);
		entite loadEntity(string entitypath);
};

#endif
