#ifndef arme_h
#define arme_h

#include "../entite/entite.h"

class arme : public entite{
	private:
		int portee;
	public:
		arme(string t, int p, int f);
		arme(arme& copie);
		~arme();
		void subirDegats();
		int getPortee();
};

#endif
