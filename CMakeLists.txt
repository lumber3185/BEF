#Projet
cmake_minimum_required(VERSION 3.6)
project(BEF DESCRIPTION "Best Ennemies Forever")
set(CMAKE_CXX_STANDARD 17)
add_definitions(-Wall -Wextra)

#chemins de sortie
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#PREREQUIS
find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

#modules :
#add_library(nom_du_module  STATIC src/nom_du_module.hpp src/nom_du_module.cpp)
add_library(entite STATIC src/forge/entite/entite.h src/forge/entite/entite.cpp)
add_library(arme STATIC src/forge/arme/arme.h src/forge/arme/arme.cpp)
add_library(filemanager STATIC src/forge/filemanager/FileManager.h src/forge/filemanager/FileManager.cpp)
add_library(terrain STATIC src/forge/terrain/Terrain.h src/forge/terrain/Terrain.cpp)
add_library(obstacle STATIC src/forge/obstacle/obstacle.h src/forge/obstacle/obstacle.cpp)
add_library(editeur STATIC src/forge/editeur/Editeur.h src/forge/editeur/Editeur.cpp)
add_library(menu STATIC src/gui/menu/menu.hpp src/gui/menu/menu.cpp)
add_library(worldgui STATIC src/gui/worldgui/worldgui.hpp src/gui/worldgui/worldgui.cpp)
add_library(editorgui STATIC src/gui/editorgui/editorgui.hpp src/gui/editorgui/editorgui.cpp)
add_library(personnage STATIC src/forge/personnage/personnage.h src/forge/personnage/personnage.cpp)
add_library(IA STATIC src/forge/IA/IA.h src/forge/IA/IA.cpp)

#linkage des librairies
target_link_libraries(arme PUBLIC entite)
target_link_libraries(obstacle PUBLIC entite)
target_link_libraries(terrain PUBLIC entite obstacle arme personnage)
target_link_libraries(filemanager PUBLIC entite terrain)
target_link_libraries(menu PUBLIC worldgui editeur)
target_link_libraries(worldgui PUBLIC terrain)
target_link_libraries(editeur PUBLIC terrain filemanager)
target_link_libraries(editorgui PUBLIC terrain editeur)
target_link_libraries(personnage PUBLIC entite terrain arme)
target_link_libraries(IA PUBLIC personnage terrain arme entite)

#exec final
#NE PAS TOUCHER
add_executable(bef src/main.cpp)

#linkage des modules :
#ajouter le nom du module de "modules :" apres "PUBLIC"
target_link_libraries(bef PUBLIC sfml-graphics sfml-audio sfml-window sfml-system menu entite arme filemanager terrain obstacle worldgui editeur editorgui personnage IA) #ajouter un nom de module apres PUBLIC (separe par un espace)
