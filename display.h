#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <vector>
#include <iostream>
#include <string>
#include "floor.h"

class Tile;

class Display {
	Floor *f;

	std::vector<std::vector<char>> board;

	std::string race;
	int hp;
	int atk;
	int def;
	std::string action;

	int floorNum;

public:
	// constructor and destructor
	Display();
	~Display();

	// accessor and mutator
	void setFloor(Floor *f);

	std::string getRace();
	void setRace(PC &pc);

	int getHP();
	void setHP(PC &pc);

	int getAtk();
	void setAtk(PC &pc);

	int getDef();
	void setDef(PC &pc);

	std::string getAction();
	void setAction(std::string act);

	int getFloorNum();
	void setFloorNum(int num);

	// other methods
	void displayFloor(Floor &f);
	void displayStats();

	void update(Tile &, std::string str);
	void update(PC *pc);

};

std::ostream &operator<<(std::ostream &out, Display &d);

#endif
