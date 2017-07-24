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
class Gold;
class Factory;

class Floor {
	// list of vectors of points for each class that will make up one floor
	std::vector<std::shared_ptr<Chamber>> chambers;

	std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
	
	std::shared_ptr<Stairs> st;
	bool hasStairs = false;

	// list of vectors containing Characters and Items
	std::vector<std::shared_ptr<NPC>> enemies;
	std::vector<std::shared_ptr<Potion>> potions;
	std::vector<std::shared_ptr<Gold>> treasure;

	std::shared_ptr<PC> player;
	bool hasPlayer = false;

	int position;
	int numChambers;

	std::shared_ptr<Display> d;
	std::shared_ptr<Factory> f;

	int maxPotion;
	int numPotion;

	int maxTreasure;
	int numTreasure;

	int maxEnemy;
	int numEnemy;

public:
	// constructor and destructors
	Floor(int position);
	~Floor();

	// accessors and mutators
	std::shared_ptr<Chamber> & getChamber(int index);
	std::shared_ptr<Tile> & getTile(int x, int y);
	std::shared_ptr<Stairs> & getStairs(int index);

	std::shared_ptr<NPC> & getNPC(int index);
	std::shared_ptr<Potion> & getPotion(int index);
	std::shared_ptr<Gold> & getGold(int index);

	std::shared_ptr<PC> & getPlayer();

	int getPosition();

	Display & getDisplay() const;
	Factory & getFactory() const;

	int getMaxPotion();
	int getNumPotion();

	int getMaxTreasure();
	int getNumTreasure();

	int getMaxEnemy();
	int getNumEnemy();

	// all spawning functions
	void spawnPC();
	void spawnStairs();
	void spawnEnemy();
	void spawnPotion();
	void spawnTreasure();

	// other methods
	void constructObject(int x, int y, char input);

	void oneChamber(int id, std::shared_ptr<Tile> t);
	void constructChamber(int id);

	void constructFloor(std::istream &input, int start);
};

std::ostream &operator<<(std::ostream &out, const Floor &f);

#endif
