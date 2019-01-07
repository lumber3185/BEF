#ifndef menu_HPP
#define menu_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../worldgui/worldgui.hpp"
#include "../../forge/editeur/Editeur.h"
#include "../play_submenu/play_submenu.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
    int selectItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    
public:
    Menu(float width, float height);
    bool is_on;
    void draw(sf::RenderWindow &window);
 
    //Deplacement vers le haut dans le menu
    void MoveUp();
    //Deplacement vers le bas dans le menu
    void MoveDown();
    //Renvoi de l'item selectionne
    int GetPressedItem();

    void event_handler(sf::Event event, Worldgui &worldgui, Editeur &editeur, Play_submenu &play_submenu);
    ~Menu();
};

#endif // !menu_HPP

