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
    sf::Sprite grass1_sprite;
    sf::Sprite grass2_sprite;

public:
    
    bool is_on;
    

Worldgui(int width, int height, Terrain &t);

void draw(sf::RenderWindow &window, Terrain t);

void draw_a_tile();
~Worldgui();
};



#endif // !worldgui_HPP
