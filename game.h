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
 	void switchFloor(int floor);
 	void displayFloor(int floor);
 	void nextTurn();
 	void spawn(int x, int y, std::string str);

 	void descend(PC &pc);

 	void freezeEnemy();
 	void pcMove(int dir);
 	void pcUse(int dir);
 	void pcAtk(int dir);
 	
 	Game(std::istream &input, std::string race);
 	~Game();
};

#endif