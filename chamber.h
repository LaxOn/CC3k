#ifndef _CHAMBER_H_
#define _CHAMBER_H_

#include <memory>
#include <vector>
#include <string>

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

	std::vector<Tile *> tiles;
	
	//std::shared_ptr<Stairs> st;

	// list of vectors containing Characters and Items
	//std::vector<std::shared_ptr<NPC>> enemies;
	//std::vector<std::shared_ptr<Potion>> potions;
	//std::vector<std::shared_ptr<Gold>> treasure;

	bool has_player = false;

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
	void addTile(Tile *t);
	Tile *getTile(int index);
	//std::shared_ptr<Tile> & getTile(int x, int y);
	//std::shared_ptr<Stairs> & getStairs(int index);

	//std::shared_ptr<NPC> & getNPC(int index);
	//std::shared_ptr<Potion> & getPotion(int index);
	//std::shared_ptr<Gold> & getGold(int index);

	//std::shared_ptr<PC> & getPlayer();

	bool getHas_Player();
	void setHas_Player(bool b);
	
	int getPosition();
	int getNumTiles();

	int getNumPotion();
	int getNumTreasure();
	int getNumEnemy();

	bool getHasStairs();
	void setHasStairs(bool b);

	// other methods
	Tile &getRandomTile(Factory *f);
	void spawnPC(Factory *f, std::string race);
	void spawnEnemy(Factory *f);
	void spawnPotion(Factory *f);
	void spawnGold(Factory *f);
};

#endif
