#include <iostream>
#include <fstream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "./forge/terrain/Terrain.h"
#include "./forge/filemanager/FileManager.h"
#include "forge/terrain/Terrain.h"
#include "forge/filemanager/FileManager.h"
#include "forge/editeur/Editeur.h"
#include "gui/menu/menu.hpp"

using namespace std;

int main(){
	Terrain t(10,10);
	FileManager f("defaut", "terrain");
	try{
		f.loadTerrain(t);
		cout << t;
		FileManager saver("default2", "terrain");
		saver.saveTerrain(t, "default2");
	}
	catch(const char* msg){
		cerr << msg;
	}


	return 0;
}
