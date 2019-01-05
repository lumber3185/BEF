#ifndef arme_h
#define arme_h

#include "../entite/entite.h"

class arme : public entite{
	private:
		int portee;
	public:
		arme(string t = "arme", int p = 0, int f = -1);
		arme(arme& copie);
		~arme();
		void subirDegats();
		int getPortee();
		void setPortee(int p);
};

#endif
