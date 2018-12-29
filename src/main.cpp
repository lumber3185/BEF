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
#include "gui/worldgui/worldgui.hpp"

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

	int size_x = 800;//aller chercher la taille du monde
	int size_y = 600;//idem
	obstacle o("arbre", 3);
	arme a("pistolet",5, 2);
	t.ajoutEntite(o, 2, 2);
	t.ajoutEntite(a,1,3);
	cout << t << endl;

	sf::RenderWindow window;
	window.create(sf::VideoMode(size_x, size_y), "BEF");

	Menu menu(window.getSize().x, window.getSize().y);
	Worldgui worldgui(window.getSize().x, window.getSize().y,t);


	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::KeyReleased){
				if(worldgui.is_on){
					worldgui.event_handler(event);
				}
				if(menu.is_on){
					menu.event_handler(event,worldgui);
				}
			}
			if(event.type == sf::Event::Closed)
			window.close();
		}
		//nettoyage fenetre
		window.clear(sf::Color::Black);

		//draw here
		if(menu.is_on){
			menu.draw(window);
		}

		if(worldgui.is_on){
			worldgui.draw(window,t);
		}

		window.display();

	return 0;
	}
}
