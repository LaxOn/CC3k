#ifndef _CHAMBER_H_
#define _CHAMBER_H_

#include <memory>
#include <vector>

class Factory;
class Chamber;
class Tile;
class Stairs;
class Display;
class NPC;
class PC;
class Potion;
class Gold;

class Chamber {
	int numTiles;

	std::vector<std::shared_ptr<Tile>> tiles;
	
	//std::shared_ptr<Stairs> st;

	// list of vectors containing Characters and Items
	std::vector<std::shared_ptr<NPC>> enemies;
	std::vector<std::shared_ptr<Potion>> potions;
	std::vector<std::shared_ptr<Gold>> treasure;

	//std::shared_ptr<PC> player;

	int position;

	int numPotion;
	int numTreasure;
	int numEnemy;

	bool hasStairs = false;

public:
	// accessors and mutators
	Chamber(int position);
	~Chamber();

	// accessors and mutators
	void addTile(std::shared_ptr<Tile> t);
	std::shared_ptr<Tile> & getTile(int index);
	//std::shared_ptr<Tile> & getTile(int x, int y);
	//std::shared_ptr<Stairs> & getStairs(int index);

	std::shared_ptr<NPC> & getNPC(int index);
	std::shared_ptr<Potion> & getPotion(int index);
	std::shared_ptr<Gold> & getGold(int index);

	//std::shared_ptr<PC> & getPlayer();

	int getPosition();
	int getNumTiles();

	int getNumPotion();
	int getNumTreasure();
	int getNumEnemy();

	bool getHasStairs();
	void setHasStairs(bool b);

	std::shared_ptr<Factory> & getFactory();

	// other methods
	Tile &getRandomTile(std::shared_ptr<Factory> f);
	void spawnPC(std::shared_ptr<Factory> f);
	void spawnEnemy(std::shared_ptr<Factory> f);
	void spawnPotion(std::shared_ptr<Factory> f);
	void spawnGold(std::shared_ptr<Factory> f);
};

#endif
