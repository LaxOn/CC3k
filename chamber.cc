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
void Chamber::addTile(std::shared_ptr<Tile> t) {
	tiles.push_back(t);
	++numTiles;
}

shared_ptr<Tile> & Chamber::getTile(int index) {
	return tiles[index];
}

//std::shared_ptr<Stairs> & getStairs(int index);

shared_ptr<NPC> & Chamber::getNPC(int index) {
	return enemies[index];
}

shared_ptr<Potion> & Chamber::getPotion(int index) {
	return potions[index];
}

shared_ptr<Gold> & Chamber::getGold(int index) {
	return treasure[index];
}

//std::shared_ptr<PC> & getPlayer();

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
Tile &Chamber::getRandomTile(shared_ptr<Factory> f) {
	int unoccupied = 0;
	for (int i = 0; i < numTiles; ++i) {
		if (tiles[i]->getOccupy() == 0) ++unoccupied;
	}

	int whichOne = f->randInt(unoccupied - 1);

	int index = 0;
	while (index < numTiles && whichOne > 0) {
		if (tiles[index]->getOccupy() == 0) --whichOne;
		++index;
	}
	//cout << "random tile chosen" << endl;
	return *tiles[index];
}

void Chamber::spawnPC(shared_ptr<Factory> f) {
	//f->addPC(getRandomTile(f));
}

void Chamber::spawnEnemy(std::shared_ptr<Factory> f) {
	//cout << "spawning enemy" << endl;
	//f->addEnemy(getRandomTile(f));
	++numEnemy;
}

void Chamber::spawnPotion(std::shared_ptr<Factory> f) {
	//cout << "spawning potion" << endl;
	//f->addPotion(getRandomTile(f));
	++numPotion;
}

void Chamber::spawnGold(std::shared_ptr<Factory> f) {
	//cout << "spawning gold" << endl;
	//f->addGold(getRandomTile(f));
	++numTreasure;
}
