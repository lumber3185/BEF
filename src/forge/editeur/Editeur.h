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
	Editeur(Terrain t, int x, int y);
	~Editeur();
	int getPosX() const;
	int getPosY() const;
	Terrain getPlateau() const;
	void user_action();
	void move(string direction);
	void add();
	void rmv();
	void saveLevel();
	void loadLevel();
	friend ostream& operator<<(ostream& flux, Editeur& e);
};

}

#endif
