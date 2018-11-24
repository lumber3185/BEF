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
    sf::FloatRect textRect = menu[0].getLocalBounds();
    menu[0].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    menu[0].setPosition(sf::Vector2f(width/2.0f, height/(MAX_NUMBER_OF_ITEMS + 1) * 1.0f));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Create");
    textRect = menu[1].getLocalBounds();
    menu[1].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    menu[1].setPosition(sf::Vector2f(width/2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.0f));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Test");
    textRect = menu[2].getLocalBounds();
    menu[2].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    menu[2].setPosition(sf::Vector2f(width/2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 3.0f));

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

void Menu::event_handler(sf::Event event){
    switch (event.key.code){
        case sf::Keyboard::Z :
            MoveUp();
            break;
		case sf::Keyboard::Up :
			MoveUp();
			break;
        case sf::Keyboard::S :
            MoveDown();
            break;
		case sf::Keyboard::Down:
			MoveDown();
			break;
		case sf::Keyboard::Return:
			switch (GetPressedItem()){
			    case 0:
		            std::cout << "Play button has been pressed" << std::endl;
					break;
				case 1:
					std::cout << "Create button has been pressed" << std::endl;
					break;
				case 2:
					std::cout << "Test button has been pressed" << std::endl;
					break;
			}
	}
}

Menu::~Menu(){
};
