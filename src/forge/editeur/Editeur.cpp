#include "Editeur.h"

using namespace std;

Editeur::Editeur(Terrain t, int x=0, int y=0): PosX(x), PosY(y), plateau(t) {
	is_on=0;
};

Editeur::~Editeur() {};

int Editeur::getPosX() const {
	return PosX;
};

int Editeur::getPosY() const {
	return PosY;
};

Terrain Editeur::getPlateau() const {
	return plateau;
}

void Editeur::user_action(sf::Event event) {
	
	switch (event.key.code)
	{
		case sf::Keyboard::Z :
			move("up");
			break;
		case sf::Keyboard::S :
			move("down");
			break;
		case sf::Keyboard::D :
			move("right");
			break;
		case sf::Keyboard::Q :
			move("left");
			break;
		case sf::Keyboard::L :
			loadLevel();
			break;
		case sf::Keyboard::W :
			saveLevel();
			break;
		case sf::Keyboard::A :
			add();
			break;
		case sf::Keyboard::E :
			rmv();
			break;
		default:
			std::cout << "unbound key" << std::endl;
			break;
	}
}

void Editeur::move(string direction) {
	// /!\ Missing bound check
	if(direction ==  "up" ) PosY--;//inverted
	else if(direction == "right") PosX++;
	else if(direction == "down") PosY++;//inverted
	else if(direction == "left") PosX--;
	else cout << "C'est par ou ca ? '" << direction << "' ?! (direction invalide)" << endl;
};

void Editeur::add() {
	cout << "Quelle entite voulez vous ajouter ?" << endl;
	string input = "";
	cin >> input;
	FileManager chargement(input, "entite");
	plateau.ajoutEntite(*chargement.loadEntity(input),PosX,PosY);
};

void Editeur::rmv() {
	plateau.retireEntite(PosX,PosY);
};

void Editeur::saveLevel() {
	cout << "Sauvegarde réussie" << endl;
};

void Editeur::loadLevel() {
	cout << "Chargement réussi" << endl;
};

ostream& operator<<(ostream& flux, Editeur& e) {
	flux << "editeur aux coordonnées : " << e.getPosX() << ", " << e.getPosY() << endl;
	return flux;
};

void Editeur::set_IsOn(bool i){
	this->is_on = i;
}
