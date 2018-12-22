#include "worldgui.hpp"

Worldgui::Worldgui(int input_width, int input_height, Terrain T){
    this->height = input_height;
    this->width = input_width;
    this->is_on = 1;

    sizeoftile_x = width/T.getX();
    sizeoftile_y = height/T.getY();
}

void Worldgui::draw(sf::RenderWindow &window, Terrain T){
    //coredump -> test for one fixed rectangle
    sf::RectangleShape tile[width][height];
    //alloc?
    sf::Texture grass1;

    if(!grass1.loadFromFile("../../../res/sprites/tileGrass1.png")){
        cerr << "Failed to load grass1 texture";
    }

    for(int x = 0; x < this->width; x++){
        for(int y = 0; y < this->height; y++){
            if(T.getEntite(x,y) != nullptr){
                std::cout << T.getEntite(x,y)->getType()  << std::endl;
            }
            else{
                tile[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                tile[x][y].setPosition(x*((1/2)*sizeoftile_x), y*((1/2) * sizeoftile_y));
                tile[x][y].setTexture(&grass1);
            }
            window.draw(tile[x][y]);
        }
    }
}

Worldgui::~Worldgui(){
}
