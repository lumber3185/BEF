#include "menu.hpp"


Menu::Menu(float width, float height){

    if(!font.loadFromFile("res/arial.ttf"))
    {
        std::cerr << "Missing ttf file";
        exit(1);
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Create");
    menu[1].setPosition(sf::Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Test");
    menu[2].setPosition(sf::Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    //add more menus here and change MAX_NUMBER_OF_ITEMS in "menu.hpp"

    //first highlighted menu is always menu 0
    selectItemIndex = 0;

}

void Menu::MoveUp(){
    if(selectItemIndex - 1 >= 0){
        menu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex--;
        menu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown(){
    if(selectItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex++;
        menu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::GetPressedItem(){
    return selectItemIndex;
}

void Menu::draw(sf::RenderWindow &window){
        for(int i=0 ; i < MAX_NUMBER_OF_ITEMS; i++){
            window.draw(menu[i]);
        }
}

Menu::~Menu(){
};
