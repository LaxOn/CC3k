#include "floor.h"
#include "display.h"
#include "npc.h"
#include "pc.h"
#include "potion.h"
#include "gold.h"
#include "chamber.h"
#include "tile.h"
#include "basictile.h"
#include "tiledecorator.h"
#include "passage.h"
#include "stairs.h"
#include "door.h"
#include "wall.h"
#include "none.h"
#include <vector>

using namespace std;

// constructor and destructors
Floor::Floor(int position) :
	//st{make_shared<Stairs>ptr}, player{make_shared<PC>ptr}, 
	position{position}, d{make_shared<Display>()}, 
	maxPotion{10}, maxEnemy{20} {
	d->setFloor(this);
	d->setFloorNum(this);
}

Floor::~Floor() {}

// accessors and mutators
shared_ptr<Chamber> & Floor::getChamber(int index) {
	return chambers[index];
}

shared_ptr<Tile> & Floor::getTile(int x, int y) {
	return tiles[x][y];
}

shared_ptr<Stairs> & Floor::getStairs(int index) {
	return st;
}

shared_ptr<NPC> & Floor::getNPC(int index) {
	return enemies[index];
}

shared_ptr<Potion> & Floor::getPotion(int index) {
	return potions[index];
}

shared_ptr<Gold> & Floor::getGold(int index) {
	return treasure[index];
}

shared_ptr<PC> & Floor::getPlayer() {
	return player;
}

int Floor::getPosition() {
	return position;
}

Display & Floor::getDisplay() const {
	return *d;
}

// other methods
void Floor::constructFloor() {
	// not sure if this is needed
}

void Floor::constructObject(int x, int y, char input) {
	if (input == '@') {

	} else if (input == 'H') {

	} else if (input == 'W') {

	} else if (input == 'E') {

	} else if (input == 'O') {

	} else if (input == 'M') {

	} else if (input == 'D') {

	} else if (input == 'L') {

	} else if (input == 'P') {

	} else if (input == 'G') {

	} else if (input == 92) {
		tiles[x][y] = make_shared<Stairs> ((make_shared<BasicTile> (x, y, d)));
	} else {
		tiles[x][y] = make_shared<BasicTile> (x, y, d);
	}
}

void Floor::constructFloor(istream &input, int start) {
	string line;

	// construct all Tiles accordingly
	tiles.resize(25);
	for (int i = 0; i < 25; ++i) {
		tiles[i].resize(79);
		getline(input, line);
		for (int j = 0; j < 79; ++j) {
			if (line[j] == '|') {
				tiles[i][j] = make_shared<Wall> ((make_shared<BasicTile> (i, j, d)), 1);
			} else if (line[j] == ' ') {
				tiles[i][j] = make_shared<None> ((make_shared<BasicTile> (i, j, d)));
			} else if (line[j] == '-') {
				tiles[i][j] = make_shared<Wall> ((make_shared<BasicTile> (i, j, d)), 0);
			} else if (line[j] == '#') {
				tiles[i][j] = make_shared<Passage> ((make_shared<BasicTile> (i, j, d)));
			} else if (line[j] == '+') {
				tiles[i][j] = make_shared<Door> ((make_shared<BasicTile> (i, j, d)));
			} else {
				Floor::constructObject(i, j, line[i]);
			}
		}
	}

	d->defaultFloor();

	// setting up neigbours for all Tiles
	for (int i = 0; i < 25; ++i) {
		for (int j = 0; j < 79; ++j) {
			//cout << "neighbour construction at : " << i << " " << j << endl;
			// the neighbours can be identified by position in the vector (integer 0-9 inclusive)
			shared_ptr<BasicTile> ptr;
			if (i - 1 < 0 && j - 1 < 0) {
				//cout << "tracker 1" << endl;
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i][j + 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i + 1][j]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j + 1]);
			} else if (i - 1 < 0 && j + 1 > 78) {
				//cout << "tracker 2" << endl;
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i][j - 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i + 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j]);
				tiles[i][j]->addNeighbr(ptr);
			} else if (i - 1 < 0) {
				//cout << "tracker 3" << endl;
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i][j + 1]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j + 1]);
			} else if (i + 1 > 24 && j - 1 < 0) {
				//cout << "tracker 4" << endl;
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i - 1][j]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j + 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i][j + 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
			} else if (i + 1 > 24 && j + 1 > 78) {
				//cout << "tracker 5" << endl;
				tiles[i][j]->addNeighbr(tiles[i - 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i][j - 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
			} else if (i + 1 > 24) {
				//cout << "tracker 6" << endl;
				tiles[i][j]->addNeighbr(tiles[i - 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j + 1]);
				tiles[i][j]->addNeighbr(tiles[i][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i][j + 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(ptr);
			} else if (j - 1 < 0) {
				//cout << "tracker 7" << endl;
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i - 1][j]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j + 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i][j + 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i + 1][j]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j + 1]);
			} else if (j + 1 > 78) {
				//cout << "tracker 8" << endl;
				tiles[i][j]->addNeighbr(tiles[i - 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i][j - 1]);
				tiles[i][j]->addNeighbr(ptr);
				tiles[i][j]->addNeighbr(tiles[i + 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j]);
				tiles[i][j]->addNeighbr(ptr);
			} else {
				//cout << "tracker 9" << endl;
				tiles[i][j]->addNeighbr(tiles[i - 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j]);
				tiles[i][j]->addNeighbr(tiles[i - 1][j + 1]);
				tiles[i][j]->addNeighbr(tiles[i][j + 1]);
				tiles[i][j]->addNeighbr(tiles[i][j + 1]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j - 1]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j]);
				tiles[i][j]->addNeighbr(tiles[i + 1][j + 1]);
			}
		}
	}

	// testing neighbours
	/*
	int a = 24; 
	int b = 78;
	for (int i = 0; i < 8; ++ i) {
		if ((tiles[a][b]->getNeighbr(i)) == nullptr) {
			cout << "?";
		} else if ((tiles[a][b]->getNeighbr(i))->getType() == 0) {
			cout << '.';
		} else if ((tiles[a][b]->getNeighbr(i))->getType() == 1) {
			cout << '#';
		} else if ((tiles[a][b]->getNeighbr(i))->getType() == 2) {
			cout << 92;
		} else if ((tiles[a][b]->getNeighbr(i))->getType() == 3) {
			cout << '+';
		} else if ((tiles[a][b]->getNeighbr(i))->getType() == 4 
					&& (tiles[a][b]->getNeighbr(i))->getSideWall() == 1) {
			cout << '|';
		} else if ((tiles[a][b]->getNeighbr(i))->getType() == 4 
					&& (tiles[a][b]->getNeighbr(i))->getSideWall() == 0){
			cout << '-';
		} else if ((tiles[a][b]->getNeighbr(i))->getType() == 5) {
			cout << ' ';
		}
		if (i == 3) cout << "*";
		if (i == 2 || i == 4 || i == 7) cout << endl;
	}
	*/
}

std::ostream & operator<<(ostream &out, const Floor &f) {
	out << f.getDisplay();
	return out;
}
