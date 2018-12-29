#include "Editeur.h"

using namespace std;

Editeur::Editeur(Terrain t, int x=0, int y=0): PosX(x), PosY(y), plateau(t) {};

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

void Editeur::user_action() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		move("up");
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move("right");
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		move("down");
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		move("left");
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		loadLevel();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		saveLevel();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		add();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		rmv();
	}
}

void Editeur::move(string direction) {
	if(direction ==  "up") PosY++;
	else if(direction == "right") PosX++;
	else if(direction == "down") PosY--;
	else if(direction == "left") PosX--;
	else cout << "C'est par ou ca ? '" << direction << "' ?! (direction invalide)" << endl;
};

void Editeur::add() {
	cout << "Quelle entite voulez vous ajouter ?" << endl;
	string input = "";
	cin >> input;
	FileManager chargement(input);
	plateau.ajoutEntite(chargement.loadEntity(input),this->PosX,this->PosY);
};

void Editeur::rmv() {
	plateau.retireEntite(this->PosX,this->PosY);
};

void Editeur::saveLevel() {
	cout << "Sauvegarde réussie" << endl;
};

void Editeur::loadLevel() {
	cout << 'Chargement réussi' << endl;
};

ostream& operator<<(ostream& flux, Editeur e) {
	flux << "editeur aux coordonnées : " << e.getPosX() << ", " << e.getPosY() << endl;
	return flux;
};
