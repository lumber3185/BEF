#ifndef arme_h
#define arme_h

#include "entite.h"

class arme : public entite{
	private:
		int portee;
	public:
		arme();
		arme(int p);
		~arme();
		void subirDegats();
		int getPortee();
};

#endif
