#include "worldgui.hpp"
#include <random>
#include <functional>

Worldgui::Worldgui(int input_width, int input_height, Terrain T){
    this->height = input_height;
    this->width = input_width;
    //off by default
    this->is_on = 0;

    sizeoftile_x = width/T.getX();
    sizeoftile_y = height/T.getY();
}

void Worldgui::draw(sf::RenderWindow &window, Terrain T){
    
    //generate random bool
    auto gen = std::bind(std::uniform_int_distribution<>(0,1), std::default_random_engine());

    //create all needed shapes grids
    sf::RectangleShape grass[T.getX()][T.getY()];
    sf::RectangleShape objects[T.getX()][T.getY()];
    
    //create all needed textures
    sf::Texture grass1;
    sf::Texture grass2;
    sf::Texture tree_large;

    //load all needed textures
    if(!grass1.loadFromFile("res/sprites/tileGrass1.png")){
        cerr << "Failed to load grass1 texture";
    }
    if(!grass2.loadFromFile("res/sprites/tileGrass2.png")){
        cerr << "failed to load grass2 texture";
    }
    if(!tree_large.loadFromFile("res/sprites/treeGreen_large.png")){
        cerr << "failed to load tree_large";
    }
    
    //drawing loop
    for(int x = 0; x < T.getX(); x++){
        for(int y = 0; y < T.getY(); y++){
            
            if(gen()){ //display two types of grass
                    grass[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                    grass[x][y].setPosition(x*sizeoftile_x, y*sizeoftile_y);
                    grass[x][y].setTexture(&grass1);
                }
                else{
                    grass[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                    grass[x][y].setPosition(x*sizeoftile_x, y*sizeoftile_y);
                    grass[x][y].setTexture(&grass2);
                }

            if(T.getEntite(x,y) != nullptr){
                if(T.getEntite(x,y)->getType() == "arbre"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                    objects[x][y].setPosition(x*sizeoftile_x, y*sizeoftile_y);
                    objects[x][y].setTexture(&tree_large);
                }
            }
            //draw grass layer
            window.draw(grass[x][y]);
            //draw object on top of grass
            window.draw(objects[x][y]);
        }
    }
}

void Worldgui::event_handler(sf::Event event){
    
    switch (event.key.code)
    {
        case sf::Keyboard::Space:
            std::cout << "pressed space" << std::endl;
            break;
    
        default:
            std::cout << "default key pressed" << std::endl;
            break;
    }
}

void Worldgui::set_IsOn(bool i){
    this->is_on = i;
}

Worldgui::~Worldgui(){
}
