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
	public:
		FileManager(string filepath);
		~FileManager();
		Terrain loadTerrain();
		void saveTerrain(Terrain T);
		entite& loadEntity(string entitypath);
};

#endif
