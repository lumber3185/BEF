#include "test.hpp"

void tests(){
    std::cout << "Creation d'un terrain de taille 12 * 12" << endl;
    Terrain t(12,12);
    cout << t << endl;
    std::cout << "Creation de deux entitées, arbre et pistolet" << endl;
    obstacle o("arbre", 3);
	arme a("pistolet", 2, 5);
    std::cout << "Ajout des entitées sur le terrain" << endl;
    t.ajoutEntite(o, 2, 2);
	t.ajoutEntite(a,3,3);
        std::cout << "Création d'un editeur" << endl;
    Editeur editeur(t,6,6);
    cout << editeur << endl;
    cout << t << endl;
	FileManager f("default", "terrain");
	try{
        std::cout << "Chargement d'un terrain" << endl;
		f.loadTerrain(t);
        cout << t << endl;
        std::cout << "sauvegarde d'un terrain" << endl;
		FileManager saver("default2", "terrain");
		saver.saveTerrain(t, "default2");
        cout << t << endl;
	}
	catch(const char* msg){
		cerr << msg;
	}
    std::cout << "Creation d'un personnage et d'une IA" << endl;
    personnage p1(t);
    IA ia(t);
    cout << t << endl;
    cout << p1<< endl;
	cout << ia << endl;
    std::cout << "Deplacement du joueur" << endl;
    p1.mouv(t);
    std::cout << "Le joueur tire" << endl;
    p1.tir(t);
}
