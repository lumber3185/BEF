#include "worldgui.hpp"

Worldgui::Worldgui(int width, int height, Terrain &t){
    this->is_on = 0;
    //0
    sf::Texture grass1;
    if(!grass1.loadFromFile("../../../res/sprites/tileGrass1.png")){
        cerr << "Failed to load Grass1";
    }
    grass1_sprite.setTexture(grass1);


    //1
    sf::Texture grass2;
    if(!grass2.loadFromFile("../../../res/sprites/tileGrass2.png")){
        cerr << "Failed to load Grass2";
    }
    grass2_sprite.setTexture(grass2);

    //2


    //other
    sizeoftile_x = width/t.getX();
    sizeoftile_y = height/t.getY();
}


void Worldgui::draw(sf::RenderWindow &window,Terrain t){
    for(int x = 0; this->width; x++){
        for(int y = 0; this->height; y++){
            if(t.getEntite(x,y) != nullptr){
                t.getEntite(x,y).getType();
            }
            else{
                draw_a_tile();
            }
        }
    }
}

Worldgui::~Worldgui(){
}; 
