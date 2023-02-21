# Pac-Man

## Description

Pac-Man, the video game...

## Usage

This project can be built using CMake.  

First set up the *build* folder:
```bash
mkdir build
cd build
cmake -S ../ -B ./
cmake --build ./
```
The use one of the following command to build the project:
```bash
cmake --build ./
```
```bash
cmake --build ./ -j4 # Use 4 CPU cores
```
Simply launch the executable and enjoy!
```bash
./pacman
```

## References

- Lazy Foo' Productions: [SDL tutorials](https://lazyfoo.net/tutorials/SDL/index.php)  
- Game Developper: [The Pac-Man Dossier](https://www.gamedeveloper.com/design/the-pac-man-dossier)  
- Fandom: [Pac-Man Wiki](https://pacman.fandom.com/wiki/Maze_Ghost_AI_Behaviors)

## To do list

- CMake  
- Logger  
- Inline constructors and getters  

## Team
- ALLEMAND Fabien
- LEBOT Samuel