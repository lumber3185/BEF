#ifndef arme_h
#define arme_h

#include "../entite/entite.h"

class arme : public entite{
	public:
		arme(string t = "arme", int p = 0, int f = 0);
		arme(arme& copie);
		~arme();
		void setPortee(int p);
};

#endif
