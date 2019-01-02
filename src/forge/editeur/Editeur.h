#ifndef EDITEUR_H
#define EDITEUR_H

#include <string>
#include <SFML/Graphics.hpp>
#include "../terrain/Terrain.h"
#include "../filemanager/FileManager.h"

namespace std {

class Editeur {
private:
	int PosX, PosY;
	Terrain plateau;
public:
	bool is_on;
	Editeur(Terrain t, int x, int y);
	~Editeur();
	int getPosX() const;
	int getPosY() const;
	Terrain getPlateau() const;
	void user_action(sf::Event event);
	void move(string direction);
	void add();
	void rmv();
	void saveLevel();
	void loadLevel();
	void set_IsOn(bool i);
	friend ostream& operator<<(ostream& flux, Editeur& e);
};

}

#endif
