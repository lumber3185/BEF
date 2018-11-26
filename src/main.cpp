#include <iostream>
#include <fstream>
#include <string.h>

#include "./forge/terrain/Terrain.h"
#include "./forge/filemanager/FileManager.h"

using namespace std;

int main(){
	Terrain t(5,5); obstacle o("r", 3); arme a(2);
	t.ajoutObstacle(o, 2, 2);
	t.ajoutArme(a, 3, 3);
	cout << t;
	return 0;
}
