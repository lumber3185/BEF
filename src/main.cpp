#include <iostream>
#include <fstream>
#include <string.h>

#include "./forge/terrain/Terrain.h"
#include "./forge/filemanager/FileManager.h"

using namespace std;

int main(){
	Terrain t(5,5);
	obstacle o("arbre", 3);
	arme a("pistolet",5, 2);
	t.ajoutEntite(o, 2, 2);
	t.ajoutEntite(a,1,3);
	cout << t;
	return 0;
}
