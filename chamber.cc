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

/*
shared_ptr<Tile> & Chamber::getTile(int x, int y) {
	Info result;
	for (int i = 0; i < numTiles; ++i) {
		result = tiles[i]->getInfo();
		if (result.x == x && result.y == y) return tiles[i];
	}
}
*/

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

shared_ptr<Factory> & Chamber::getFactory() {
	return f;
}

// other methods
//shared_ptr<Tile> & Chamber::getRandomTile() {
//
// }

void Chamber::spawnEnemy() {
	//f->addEnemy(getRandomTile());
}

void Chamber::spawnPotion() {

}

void Chamber::spawnGold() {

}
