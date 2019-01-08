//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//
#ifndef worldgui_HPP
#define worldgui_HPP
#include "../../forge/terrain/Terrain.h"
#include "../../forge/personnage/personnage.h"
#include "../../forge/IA/IA.h"
#include "SFML/Graphics.hpp"
#include <iostream>

//Gere l'affichage du terrain

class Worldgui
{
private:
    int width;
    int height;
    int sizeoftile_x;
    int sizeoftile_y;

public:
    
    bool is_on;
    bool ia_mode;
    

Worldgui(int width, int height, Terrain T);


sf::Texture get_Texture_grass1();

void draw(sf::RenderWindow &window,Terrain T,personnage p1, personnage p2);

void event_handler(sf::Event event,Terrain &t, personnage &p1, personnage &p2);
void event_handler(sf::Event event, Terrain &t, personnage &p1, IA &ia);

void set_IsOn(bool i);
void set_IAOn(bool i);

void draw_a_tile(string type);
~Worldgui();
};



#endif // !worldgui_HPP
