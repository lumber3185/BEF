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
	Terrain t(5,5);
	obstacle a("arbre", 2);
	t.ajoutEntite(a,2,3);
	Editeur test(t,3,3);
	cout << test << t;
}
