#include <iostream>
#include <fstream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "forge/terrain/Terrain.h"
#include "forge/filemanager/FileManager.h"
#include "gui/menu/menu.hpp"

using namespace std;

int main(){

	int size_x = 800;//aller chercher la taille du monde
	int size_y = 600;//idem

	sf::RenderWindow window;
	window.create(sf::VideoMode(size_x, size_y), "BEF");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::KeyReleased){
				menu.event_handler(event);
			}
			if(event.type == sf::Event::Closed)
			window.close();
		}
		//nettoyage fenetre
		window.clear(sf::Color::Black);

		//draw here
		menu.draw(window);

		window.display();

	}


	return 0;
}
