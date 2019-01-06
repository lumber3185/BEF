#include <iostream>
#include <fstream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unistd.h>
#include "./forge/terrain/Terrain.h"
#include "./forge/filemanager/FileManager.h"
#include "forge/terrain/Terrain.h"
#include "forge/filemanager/FileManager.h"
#include "forge/editeur/Editeur.h"
#include "gui/menu/menu.hpp"
#include "gui/worldgui/worldgui.hpp"
#include "gui/editorgui/editorgui.hpp"
#include "forge/personnage/personnage.h"

using namespace std;

int main(){
	Terrain t(10,10);
	FileManager f("default", "terrain");
	try{
		f.loadTerrain(t);
		FileManager saver("default2", "terrain");
		saver.saveTerrain(t, "default2");
	}
	catch(const char* msg){
		cerr << msg;
	}

	
	int size_x = 800;//aller chercher la taille du monde
	int size_y = 800;//idem

	obstacle o("arbre", 3);
	arme a("pistolet", 2, 5);
	Editeur editeur(t,3,4);
	
	//t.ajoutEntite(o, 2, 2);
	t.ajoutEntite(a,3,3);

	personnage p2(t,2,3);
	personnage p1(t,6,6);
	
	cout << t << endl;
	cout << p1<< endl;
	cout << p2 << endl;
	//int b = p1.mouv(t);

	//cout << b << endl;
	cout << t << endl;

	//cout << editeur << endl;

	sf::RenderWindow window;
	window.create(sf::VideoMode(size_x, size_y), "BEF");
	auto desktop = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i(desktop.width/2 -window.getSize().x/2, desktop.height/2 - window.getSize().y/2));

	Menu menu(window.getSize().x, window.getSize().y);
	Worldgui worldgui(window.getSize().x, window.getSize().y,t);
	Editorgui editorgui(window.getSize().x, window.getSize().y, editeur.getPlateau());



	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::KeyReleased){
				if(worldgui.is_on && !editeur.is_on){
					worldgui.event_handler(event,t,p1,p2);
				}
				if(menu.is_on){
					menu.event_handler(event,worldgui,editeur);
				}
				if(editeur.is_on){
					editeur.user_action(event);
				}
				if(event.key.code == sf::Keyboard::Escape){
					window.close();
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

		if(worldgui.is_on && editeur.is_on){
			worldgui.draw(window, editeur.getPlateau(),p1,p2);
			editorgui.draw(window,editeur);
		}
		if(worldgui.is_on && !editeur.is_on){
			worldgui.draw(window,t,p1,p2);
		}

		window.display();
		cout << "########" << endl;
		cout << p1 << "IN MAIN" << endl;
		cout << t << "IN MAIN" << endl;
		cout << "########" << endl;

	}
	
	return 0;
}
