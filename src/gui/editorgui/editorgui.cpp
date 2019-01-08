//GONICHON Lucas 21504002//
//LE ROUX Amélie 21600230//
//JACQUET Julien 21400579//

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

    //Initialisation du texte
    help[0].setString("A : Add (terminal)");
    help[1].setString("E : Remove");
    help[2].setString("L : Load Level (terminal)");
    help[3].setString("W : Save (terminal)");
    
    //placement du texte
    for(int i = 0; i < MAX_NUMBER_OF_KEYS; i++){
        help[i].setFont(font);
        help[i].setCharacterSize(18);
        help[i].setFillColor(sf::Color::Black);
        sf::FloatRect textRect = help[i].getLocalBounds();
        help[i].setPosition((width - 10)- textRect.width, 100 +100*i);
    }
}

void Editorgui::draw(sf::RenderWindow &window, Editeur &editeur){//fonction d'affichage de l'interface editeur
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
