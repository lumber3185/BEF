#include "editorgui.hpp"

Editorgui::Editorgui(int input_width, int input_height, Terrain T){
    this->height = input_height;
    this->width = input_width;

    sizeoftile_x = width/T.getX();
    sizeoftile_y = height/T.getY();

    if(!font.loadFromFile("res/arial.ttf")){
        std::cerr << "Missing ttf file";
        exit(1);
    }

    help[0].setString("A : add");
    help[1].setString("E : remove");
    help[2].setString("L : Load Level");
    help[3].setString("W : save");
    
    for(int i = 0; i < MAX_NUMBER_OF_KEYS; i++){
        help[i].setFont(font);
        help[i].setCharacterSize(24);
        help[i].setFillColor(sf::Color::Black);
        sf::FloatRect textRect = help[i].getLocalBounds();
        help[i].setPosition((width - 10)- textRect.width, 100 +100*i);
    }
}

void Editorgui::draw(sf::RenderWindow &window, Editeur &editeur){
    sf::RectangleShape red;
    red.setOutlineThickness(5.f);
    red.setFillColor(sf::Color(0,0,0,0));
    red.setOutlineColor(sf::Color(255,0,0));

    red.setSize(sf::Vector2f(sizeoftile_x, sizeoftile_y));
    red.setPosition(editeur.getPosX()*sizeoftile_x,editeur.getPosY()*sizeoftile_y);

    
    for(int i = 0; i < MAX_NUMBER_OF_KEYS; i++)
    {
        window.draw(help[i]);
    }
    

    window.draw(red);

}

Editorgui::~Editorgui(){

}
