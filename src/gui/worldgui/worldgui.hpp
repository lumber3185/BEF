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

public:
    
    bool is_on;
    

Worldgui(int width, int height, Terrain T);


sf::Texture get_Texture_grass1();

void draw(sf::RenderWindow &window,Terrain T);

void draw_a_tile(string type);
~Worldgui();
};



#endif // !worldgui_HPP
