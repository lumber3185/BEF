#include "worldgui.hpp"

Worldgui::Worldgui(int width, int height, Terrain &t){
    this->is_on = 0;
    //0
    if(!grass1.loadFromFile("../../../res/sprites/tileGrass1.png")){
        cerr << "Failed to load Grass1";
    }


    //1
    if(!grass2.loadFromFile("../../../res/sprites/tileGrass2.png")){
        cerr << "Failed to load Grass2";
    }

    //2


    //other
    sizeoftile_x = width/t.getX();
    sizeoftile_y = height/t.getY();
}


void Worldgui::draw(sf::RenderWindow &window,Terrain t){
    for(int x = 0; this->width; x++){
        for(int y = 0; this->height; y++){
            if(t.getEntite(x,y) != nullptr){
                if(t.getEntite(x,y)->getType() == "arbre"){
                    std::cout << "arbre" << std::endl ;
                }
                std::cout << "not grass" << std::endl;
            }
            else{
                this->draw_a_tile("grass");
            }
        }
    }
}

void Worldgui::draw_a_tile(string type, ){

    if(type == "grass"){
        sf::Sprite tile;
        tile.setTexture(grass1);
        tile.setTextureRect(sf::IntRect(sizeoftile_x,sizeoftile_y,sizeoftile_x,sizeoftile_y));
        tile.setPosition()
    }
}

Worldgui::~Worldgui(){
}


sf::Texture Worldgui::get_Texture_grass1(){
    return grass1;
}
