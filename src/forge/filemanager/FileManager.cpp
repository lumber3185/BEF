#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#include "FileManager.h"
#include "../terrain/Terrain.h"
#include "../entite/entite.h"

FileManager :: FileManager(string FilePath) : path(FilePath) {};
FileManager :: ~FileManager() {};
