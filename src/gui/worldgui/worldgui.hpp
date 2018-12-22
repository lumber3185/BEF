#ifndef worldgui_HPP
#define worldgui_HPP
#include "../../forge/terrain/Terrain.h"
#include "SFML/Graphics.hpp"
#include <iostream>


class Worldgui
{
private:
    int width;
    int height;
    int sizeoftile_x;
    int sizeoftile_y;
    sf::Texture &grass1;
    sf::Texture grass2;

public:
    
    bool is_on;
    

Worldgui(int width, int height, Terrain &t);


sf::Texture get_Texture_grass1();

void draw(sf::RenderWindow &window, Terrain t);

void draw_a_tile(string type);
~Worldgui();
};



#endif // !worldgui_HPP
