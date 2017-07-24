#include "chamber.h"
#include "floor.h"
#include "factory.h"
#include "info.h"
#include "tile.h"

using namespace std;

// accessors and mutators
Chamber::Chamber(int position) :
	numTiles{0}, position{position}, 
	numPotion{0}, numTreasure{0}, numEnemy{0} {}

Chamber::~Chamber() {}

// accessors and mutators
void Chamber::addTile(Tile *t) {
	tiles.push_back(t);
	++numTiles;
}

Tile *Chamber::getTile(int index) {
	return tiles[index];
}

//std::shared_ptr<Stairs> & getStairs(int index);
/*
shared_ptr<NPC> & Chamber::getNPC(int index) {
	return enemies[index];
}

shared_ptr<Potion> & Chamber::getPotion(int index) {
	return potions[index];
}

shared_ptr<Gold> & Chamber::getGold(int index) {
	return treasure[index];
}
*/
//std::shared_ptr<PC> & getPlayer();

bool Chamber::getHas_Player() {
	return has_player;
}

void Chamber::setHas_Player(bool b) {
	has_player = b;
}

int Chamber::getPosition() {
	return position;
}

int Chamber::getNumTiles() {
	return numTiles;
}

int Chamber::getNumPotion() {
	return numPotion;
}

int Chamber::getNumTreasure() {
	return numTreasure;
}

int Chamber::getNumEnemy(){
	return numEnemy;
}

bool Chamber::getHasStairs() {
	return hasStairs;
}

void Chamber::setHasStairs(bool b) {
	hasStairs = b;
}

// other methods
Tile &Chamber::getRandomTile(Factory *f) {
	int unoccupied = 0;
	//cout << "this chamber has " << numTiles << " tiles" << endl;
	for (int i = 0; i < numTiles; ++i) {
		if (tiles[i] != nullptr &&
			tiles[i]->getOccupy() == 0) ++unoccupied;
		//if (tiles[i] == nullptr) cout << "found null" << endl;
	}

	int whichOne = f->randInt(unoccupied);

	int index = 0;
	while (index < numTiles) {
		if (tiles[index] != nullptr &&
			tiles[index]->getOccupy() == 0) --whichOne;
		if (whichOne == 0) break;
		++index;
	}
	//cout << "random tile chosen" << endl;
	return *tiles[index];
}

void Chamber::spawnPC(Factory *f, string race) {
	f->addPC(getRandomTile(f), race);
}

void Chamber::spawnEnemy(Factory *f) {
	//cout << "spawning enemy in chamber " << position << endl;
	f->addEnemy(getRandomTile(f));
	++numEnemy;
}

void Chamber::spawnPotion(Factory *f) {
	//cout << "spawning potion" << endl;
	f->addPotion(getRandomTile(f));
	++numPotion;
}

void Chamber::spawnGold(Factory *f) {
	cout << "tracker 2 " << endl;
	//cout << "spawning gold" << endl;
	f->addGold(getRandomTile(f));
	++numTreasure;
}
