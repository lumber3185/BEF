#ifndef arme_h
#define arme_h

#include "../entite/entite.h"

class arme : public entite{
	private:
		int portee;
	public:
		arme();
		arme(int p);
		arme(int p, int f);
		~arme();
		void subirDegats();
		int getPortee();
};

#endif
