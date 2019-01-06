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
    
    //declare all needed textures
    sf::Texture grass1;
    sf::Texture grass2;
    sf::Texture tree_large;
    sf::Texture tree_small;
    sf::Texture rock_large;
    sf::Texture rock_small;
    sf::Texture pistol;
    sf::Texture bazooka;
    sf::Texture perso1;
    sf::Texture perso2;

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
    if(!tree_small.loadFromFile("res/sprites/treeGreen_small.png")){
        cerr << "failed to load tree_small";
    }
    if(!rock_large.loadFromFile("res/sprites/meteorGrey_big1.png")){
        cerr << "failed to load rock_large";
    }
    if(!rock_small.loadFromFile("res/sprites/meteorGrey_med1.png")){
        cerr << "failed to load small rock";
    }
    if(!pistol.loadFromFile("res/sprites/weapon_silencer.png")){
        cerr << "failed to load pistol";
    }
    if(!bazooka.loadFromFile("res/sprites/tank_bullet3.png")){
        cerr << "failed to load bazooka";
    }
    if(!perso1.loadFromFile("res/sprites/survivor1_stand.png")){
        cerr << "failed to load perso1";
    }
    if(!perso2.loadFromFile("res/sprites/hitman1_stand.png")){
        cerr << "failed to load perso2";
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
                if(T.getEntite(x,y)->getType() == "grosarbre"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                    objects[x][y].setPosition(x*sizeoftile_x, y*sizeoftile_y);
                    objects[x][y].setTexture(&tree_large);
                }
                if(T.getEntite(x,y)->getType() == "petitarbre"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x*5/6, sizeoftile_y*5/6));
                    // expl: |5-6| = 1 -> 1/(2*6)
                    objects[x][y].setPosition(x*sizeoftile_x+(sizeoftile_x*1/12), y*sizeoftile_y+(sizeoftile_y*1/12));
                    objects[x][y].setTexture(&tree_small);
                }
                if(T.getEntite(x,y)->getType() == "grosrocher"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                    objects[x][y].setPosition(x*sizeoftile_x, y*sizeoftile_y);
                    objects[x][y].setTexture(&rock_large);
                }
                if(T.getEntite(x,y)->getType() == "petitrocher"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x*5/6, sizeoftile_y*5/6));
                    objects[x][y].setPosition(x*sizeoftile_x+(sizeoftile_x*1/12), y*sizeoftile_y+(sizeoftile_y*1/12));
                    objects[x][y].setTexture(&rock_small);
                }
                if(T.getEntite(x,y)->getType() == "pistolet"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x*2/6, sizeoftile_y*1/6));
                    objects[x][y].setPosition(x*sizeoftile_x+(sizeoftile_x*4/12), y*sizeoftile_y+(sizeoftile_y*5/12));
                    objects[x][y].setTexture(&pistol);
                }
                if(T.getEntite(x,y)->getType() == "bazooka"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x/2, sizeoftile_y/2));
                    objects[x][y].setPosition(x*sizeoftile_x+(sizeoftile_x*1/4), y*sizeoftile_y+(sizeoftile_y*1/4));
                    objects[x][y].setTexture(&bazooka);
                }
                if(T.getEntite(x,y)->getType() == "perso1"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                    objects[x][y].setPosition(x*sizeoftile_x, y*sizeoftile_y);
                    objects[x][y].setTexture(&perso1);
                }
                if(T.getEntite(x,y)->getType() == "perso2"){
                    objects[x][y].setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
                    objects[x][y].setPosition(x*sizeoftile_x, y*sizeoftile_y);
                    objects[x][y].setTexture(&perso2);
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
