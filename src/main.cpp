#include <iostream>
#include <fstream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unistd.h>
#include "forge/terrain/Terrain.h"
#include "forge/filemanager/FileManager.h"
#include "forge/terrain/Terrain.h"
#include "forge/filemanager/FileManager.h"
#include "forge/editeur/Editeur.h"
#include "gui/menu/menu.hpp"
#include "gui/play_submenu/play_submenu.hpp"
#include "gui/worldgui/worldgui.hpp"
#include "gui/editorgui/editorgui.hpp"
#include "forge/personnage/personnage.h"
#include "forge/IA/IA.h"

using namespace std;

int main(){
	/*Terrain t(10,10);
	FileManager f("default", "terrain");
	try{
		f.loadTerrain(t);
		FileManager saver("default2", "terrain");
		saver.saveTerrain(t, "default2");
	}
	catch(const char* msg){
		cerr << msg;
	}

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
	*/

	int taille_terrain_x = 10;
	int taille_terrain_y = 10;
	int size_x = (800/taille_terrain_x)*taille_terrain_x;
	int size_y = (800/taille_terrain_y)*taille_terrain_y;
	
	Terrain t(taille_terrain_x,taille_terrain_y);
	Editeur editeur(t,taille_terrain_x/2,taille_terrain_y/2);
	personnage p1(t);
	p1.set_tour(1);
	personnage p2(t);
	IA ia(t);


	sf::RenderWindow window;
	window.create(sf::VideoMode(size_x, size_y), "BEF");
	auto desktop = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i(desktop.width/2 -window.getSize().x/2, desktop.height/2 - window.getSize().y/2));

	Menu menu(window.getSize().x, window.getSize().y);
	Play_submenu play_submenu(window.getSize().x, window.getSize().y);
	Worldgui worldgui(window.getSize().x, window.getSize().y,t);
	Editorgui editorgui(window.getSize().x, window.getSize().y, editeur.getPlateau());



	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::KeyReleased){
				if(menu.is_on){
					menu.event_handler(event,worldgui,editeur,play_submenu);
				}
				if(play_submenu.is_on){
					play_submenu.event_handler(event, t, worldgui);
				}
				if(worldgui.is_on && !editeur.is_on){
					if(worldgui.ia_mode == 0){
						worldgui.event_handler(event,t,p1,p2);
					}
					else{
						worldgui.event_handler(event,t,p1,ia);
					}	
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
		if(play_submenu.is_on){
			play_submenu.draw(window);
		}
		if(worldgui.is_on && editeur.is_on){
			worldgui.draw(window, editeur.getPlateau(),p1,p2); //affichage de la grille
			editorgui.draw(window,editeur); //touches sur le cote droit
		}
		if(worldgui.is_on && !editeur.is_on){
			if(worldgui.ia_mode == 0){
				worldgui.draw(window, t, p1, p2);
			}
			else{
				worldgui.draw(window, t, p1, ia);
				if(ia.get_tour() == 1 && p1.get_tour() == 0){
                	ia.mouvance(t);
                	ia.set_tour(0);
                	p1.set_tour(1);
					cout << ia << "IA" << endl;
            	}
			}
		}

		window.display();
		/*
		cout << "########" << endl;
		cout << p1 << "IN MAIN" << endl;
		cout << t << "IN MAIN" << endl;
		cout << "########" << endl;
		*/
		usleep(1000000);

	}
	
	return 0;
}
