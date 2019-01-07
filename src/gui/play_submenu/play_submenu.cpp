#include "play_submenu.hpp"

Play_submenu::Play_submenu(float width, float height){
    if(!font.loadFromFile("res/arial.ttf")){
        std::cerr << "missing ttf file";
        exit(1);
    }
    this->is_on = 0;

    submenu[0].setString("L : Load level (type in console)");
    submenu[1].setString("I : Player vs IA");
    submenu[2].setString("P : Player vs Player");

    for(int i = 0; i < NUMBER_OF_OPTIONS; i++){
        submenu[i].setFont(font);
        submenu[i].setCharacterSize(24);
        submenu[i].setFillColor(sf::Color::Red);
        sf::FloatRect textRect = submenu[i].getLocalBounds();
        submenu[i].setOrigin(textRect.left + textRect.width/2 , textRect.top + textRect.height/2);
        submenu[i].setPosition(sf::Vector2f(width/2, height / (NUMBER_OF_OPTIONS + 1) * (i+1)));
    }
}

void Play_submenu::draw(sf::RenderWindow &window){
    for(int i = 0; i < NUMBER_OF_OPTIONS; i++){
        window.draw(submenu[i]);
    }
}

void Play_submenu::event_handler(sf::Event event, Terrain &t, Worldgui &worldgui){
    string filename;
    switch (event.key.code){
        case sf::Keyboard::L :{
            std::cout << "Enter name of file to load" << std::endl;
            std::cin >> filename;
            FileManager f(filename, "terrain");
            f.loadTerrain(t);
            break; }
        case sf::Keyboard::I :
            std::cout << "Player vs IA" << std::endl;
            this->set_IsOn(0);
            worldgui.set_IsOn(1);
            worldgui.set_IAOn(1);
            break;
        case sf::Keyboard::P :
            std::cout << "Player VS Player" << std::endl;
            this->set_IsOn(0);
            worldgui.set_IsOn(1);
            worldgui.set_IAOn(0);
            break;
        default:
            std::cout << "default" << std::endl;
            break;
    }
}

void Play_submenu::set_IsOn(bool b){
    this->is_on = b;
}

Play_submenu::~Play_submenu(){}
