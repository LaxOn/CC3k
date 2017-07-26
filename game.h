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
	std::istream &input;

 public:
 	int getCurFloor();
 	void switchFloor(int floor);
 	void displayFloor(int floor);
 	void nextTurn();

 	void descend();

 	void freezeEnemy(bool canMove);
 	void pcMove(int dir);
 	void pcUse(int dir);
 	void pcAtk(int dir);
 	
 	Game(std::istream &input, std::string race);
 	~Game();
};

#endif