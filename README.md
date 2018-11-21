# BEF
Best Enemies Forever (Bataille en Forêt)

## Install SFML
```
sudo apt update
```
et
```
sudo apt install libsfml-dev
```
## CMAKE
```
sudo apt install cmake cmake-gui
```
Aller dans **BEF/** 
```
ccmake .
```
appuyer sur [c] puis sur [g], enfin :
```
make
```
A chaque nouveau module/fichier, il faut modifier le fichier **CMakeLists.txt** (voir dedans).

cf: [Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
