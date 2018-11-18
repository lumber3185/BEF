exe: Terrain.o FileManager.o entite.o arme.o obstacle.o main.o
	g++ Terrain.o FileManager.o main.o -o exe

main.o: main.cpp Terrain.h FileManager.h entite.h arme.h obstacle.h
	g++ -c main.cpp -o main.o -Wall
	
Terrain.o: entite.h arme.h obstacle.h Terrain.h Terrain.cpp
	g++ -c Terrain.cpp -o Terrain.o -Wall
	
FileManager.o: FileManager.cpp FileManager.h Terrain.h entite.h arme.h obstacle.h
	g++ -c FileManager.cpp -o FileManager.o -Wall

entite.o: entite.h entite.cpp
	g++ -c entite.cpp -o entite.o -Wall
	
arme.o: arme.cpp arme.h
	g++ -c arme.cpp -o arme.o -Wall

obstacle.o: obstacle.cpp obstacle.h
	g++ -c obstacle.cpp -o obstacle.o -Wall

clean:	
	rm -fr *.o
	rm -fr exe
