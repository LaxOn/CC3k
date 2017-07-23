#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <memory>

class Dungeon;

class Game {
	int curFloor;
	std::unique_ptr<Dungeon> gameDungeon;
	void near();
	std::istream &input;

 public:
 	int getCurFloor();
 	
 	void displayFloor(int floor);
 	void nextTurn();
 	void spawn(int x, int y, std::string);
 	
 	Game(std::istream &input);
 	~Game();
};

#endif