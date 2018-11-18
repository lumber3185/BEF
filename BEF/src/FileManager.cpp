#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#include "FileManager.h"
#include "Terrain.h"
#include "entite.h"

FileManager :: FileManager(string FilePath) : path(FilePath) {};
FileManager :: ~FileManager() {};
