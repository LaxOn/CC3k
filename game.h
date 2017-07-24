#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>

class Dungeon;
class PC;

class Game {
	int curFloor;
	std::unique_ptr<Dungeon> gameDungeon;
	void near();
	std::istream &input;

 public:
 	int getCurFloor();
 	
 	void displayFloor(int floor);
 	void nextTurn();
 	void spawn(int x, int y, std::string str);

 	void descend(PC &pc);
 	
 	Game(std::istream &input, std::string race);
 	~Game();
};

#endif