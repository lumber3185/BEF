#include <iostream>
#include <fstream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "./forge/terrain/Terrain.h"
#include "./forge/filemanager/FileManager.h"
#include "forge/terrain/Terrain.h"
#include "forge/filemanager/FileManager.h"
#include "gui/menu/menu.hpp"

using namespace std;

int main(){
	AppPathInitialize();
	ifstream f("./default.txt", ios::in);
	if(f) f.close();
	else cout << "nope";
	return 0;
}
