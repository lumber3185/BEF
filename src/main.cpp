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
<<<<<<< HEAD

	int size_x = 800;//aller chercher la taille du monde
	int size_y = 600;//idem

	Terrain t(5,5);
	obstacle o("arbre", 3);
	arme a("pistolet",5, 2);
	t.ajoutEntite(o, 2, 2);
	t.ajoutEntite(a,1,3);
=======
	Terrain t(5,5); obstacle o("r", 3); arme a(2);
	t.ajoutObstacle(o, 2, 2);
	t.ajoutArme(a, 3, 3);
>>>>>>> f0ee9e49d98c530d15c0e00ae00ab1b58338c89c
	cout << t;

	sf::RenderWindow window;
	window.create(sf::VideoMode(size_x, size_y), "BEF");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::KeyReleased){
				if(menu.is_on){
					menu.event_handler(event);
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

		window.display();

	}
	return 0;
}
