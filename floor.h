#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>

class Chamber;
class Tile;
class Stairs;
class Display;
class NPC;
class PC;
class Potion;

class Floor {
	// list of vectors of points for each class that will make up one floor
	std::vector<std::shared_ptr<Chamber>> chambers;
	std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
	std::shared_ptr<Stairs> st;

	// list of vectors containing Characters and Items
	std::shared_ptr<NPC> enemies;
	std::shared_ptr<Potion> potions;
	std::shared_ptr<Gold> treasure;

	std::shared_ptr<PC> player;

	int position;

	std::shared_ptr<Display> d;

protected:
	int maxPotion;
	int maxTreasure;
	int maxEnemy;

public:
	// constructor and destructors
	Floor(int position);
	~Floor();

	// accessors and mutators
	shared_ptr<Chamber> *& getChamber(int index);
	shared_ptr<Tile> *& getTile(int x, int y);
	shared_ptr<Stairs> *& getStairs(int index);

	shared_ptr<NPC> *& getNPC(int index);
	shared_ptr<Potion> *& getPotion(int index);
	shared_ptr<Gold> *& getGold(int index);

	shared_ptr<PC> *& getPlayer();

	int getPosition();

	// other methods
	void constructFloor();
	void constructFloor(istream &input, int start);
	void display();
}

void &operator<<(ostream &out, const Floor &f);

#endif
