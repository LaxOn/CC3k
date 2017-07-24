#include "floor.h"
#include "display.h"
#include "factory.h"
#include "npc.h"
#include "pc.h"
#include "potion.h"
#include "gold.h"
#include "chamber.h"
#include "tile.h"
#include "basictile.h"
#include "basicpotion.h"
#include "tiledecorator.h"
#include "passage.h"
#include "stairs.h"
#include "door.h"
#include "wall.h"
#include "none.h"

#include "humanNPC.h"
#include "dwarfNPC.h"
#include "elfNPC.h"
#include "orcNPC.h"
#include "dragonNPC.h"
#include "merchantNPC.h"
#include "halflingNPC.h"

#include "restorehealth.h"
#include "poisonhealth.h"
#include "boostatk.h"
#include "woundatk.h"
#include "boostdef.h"
#include "wounddef.h"

using namespace std;

// constructor and destructors
Floor::Floor(int position) :
	position{position}, numChambers{5},
	d{make_shared<Display>()}, f{make_shared<Factory> (d)},
	maxPotion{10}, numPotion{0},
	maxTreasure{10}, numTreasure{0},
	maxEnemy{20}, numEnemy{0} {
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

Factory & Floor::getFactory() const {
	return *f;
}

int Floor::getMaxPotion() {
	return maxPotion;
}

int Floor::getNumPotion() {
	return numPotion;
}

int Floor::getMaxTreasure() {
	return maxTreasure;
}

int Floor::getNumTreasure() {
	return numTreasure;
}

int Floor::getMaxEnemy() {
	return maxEnemy;
}

int Floor::getNumEnemy() {
	return numEnemy;
}

// all spawning functions
void Floor::spawnPC() {
	if (position == 1 && hasPlayer == false) {
		int whichChamber = f->randInt(4);
		chambers[whichChamber]->spawnPC(f);

		int number_tiles = chambers[whichChamber]->getNumTiles();
		for (int i = 0; i < number_tiles; ++i) {
			if ((chambers[whichChamber]->getTile(i))->getPC() != nullptr) {
				player = (chambers[whichChamber]->getTile(i))->getPC();
				(chambers[whichChamber]->getTile(i))->setOccupy(true);
			}
		}
		hasPlayer = true;
	}
}

void Floor::spawnStairs() {
	int whichChamber = 0;
	bool do_not_spawn = false;
	while (hasStairs == false) {
		whichChamber = f->randInt(4);
		int number_tiles = chambers[whichChamber]->getNumTiles();
		for (int i = 0; i < number_tiles; ++i) {
			if ((chambers[whichChamber]->getTile(i))->getPC() != nullptr) {
				do_not_spawn = false;
				break;
			}
		}
		if (do_not_spawn == false) {
			Info temp = (chambers[whichChamber]->getRandomTile(f).getInfo());
			tiles[temp.x][temp.y] = make_shared<Stairs> (make_shared<BasicTile> (temp.x, temp.y, *d));
			hasStairs = true;
			break;
		}
	}
}

void Floor::spawnEnemy() {
	int whichChamber = 0;

	while (numEnemy < maxEnemy) {
		whichChamber = f->randInt(4);

		chambers[whichChamber]->spawnEnemy(f);
		++numEnemy;
	}
}

void Floor::spawnPotion() {
	int whichChamber = 0;

	while (numPotion < maxPotion) {
		whichChamber = f->randInt(4);

		chambers[whichChamber]->spawnPotion(f);
		++numPotion;
	}
}

void Floor::spawnTreasure() {
	int whichChamber = 0;

	while (numTreasure < maxTreasure) {
		whichChamber = f->randInt(4);

		chambers[whichChamber]->spawnGold(f);
		++numTreasure;
	}
}

// other methods
void Floor::constructObject(int x, int y, char input) {
	//cout << input << endl;
	if (input == 'H') {
		cout << "constructing 1" << endl;
		tiles[x][y]->addNPC(make_shared<HumanNPC> (x, y, tiles[x][y].get()));
		tiles[x][y]->setOccupy(true);
		player->attach(tiles[x][y]->getNPC());
		++numEnemy;
	} else if (input == 'W') {
		cout << "constructing 2" << endl;
		tiles[x][y]->addNPC(make_shared<DwarfNPC> (x, y, tiles[x][y].get()));
		tiles[x][y]->setOccupy(true);
		player->attach(tiles[x][y]->getNPC());
		++numEnemy;
	} else if (input == 'E') {
		cout << "constructing 3" << endl;
		tiles[x][y]->addNPC(make_shared<ElfNPC> (x, y, tiles[x][y].get()));
		tiles[x][y]->setOccupy(true);
		player->attach(tiles[x][y]->getNPC());
		++numEnemy;
	} else if (input == 'O') {
		cout << "constructing 4" << endl;
		tiles[x][y]->addNPC(make_shared<OrcNPC> (x, y, tiles[x][y].get()));
		tiles[x][y]->setOccupy(true);
		player->attach(tiles[x][y]->getNPC());
		++numEnemy;
	} else if (input == 'M') {
		cout << "constructing 5" << endl;
		tiles[x][y]->addNPC(make_shared<MerchantNPC> (x, y, tiles[x][y].get()));
		tiles[x][y]->setOccupy(true);
		//cout << "DONE" << endl;
		player->attach(tiles[x][y]->getNPC());
		//cout << "DONE2" << endl;
		++numEnemy;
	} else if (input == 'D') {
		cout << "constructing 6" << endl;
		tiles[x][y]->addNPC(make_shared<DragonNPC> (x, y, tiles[x][y].get()));
		tiles[x][y]->setOccupy(true);
		player->attach(tiles[x][y]->getNPC());
		++numEnemy;
	} else if (input == 'L') {
		cout << "constructing 7" << endl;
		tiles[x][y]->addNPC(make_shared<HalflingNPC> (x, y, tiles[x][y].get()));
		tiles[x][y]->setOccupy(true);
		player->attach(tiles[x][y]->getNPC());
		++numEnemy;
	} else if (input == 'P') {
		cout << "constructing 8" << endl;
		//f->addPotion(getTile(x, y));
		++numPotion;
	} else if (input == '0') {
		cout << "constructing 9" << endl;
		tiles[x][y]->addObject(make_shared<RestoreHealth> (make_shared<BasicPotion>(0,"", true, x, y)));
		tiles[x][y]->setOccupy(true);
		++numPotion;
	} else if (input == '1') {
		cout << "constructing 10" << endl;
		tiles[x][y]->addObject(make_shared<BoostAtk> (make_shared<BasicPotion>(0,"", true, x, y)));
		tiles[x][y]->setOccupy(true);
		++numPotion;
	} else if (input == '2') {
		cout << "constructing 11" << endl;
		tiles[x][y]->addObject(make_shared<BoostDef> (make_shared<BasicPotion>(0,"", true, x, y)));
		tiles[x][y]->setOccupy(true);
		++numPotion;
	} else if (input == '3') {
		cout << "constructing 12" << endl;
		tiles[x][y]->addObject(make_shared<PoisonHealth> (make_shared<BasicPotion>(0,"", true, x, y)));
		tiles[x][y]->setOccupy(true);
		++numPotion;
	} else if (input == '4') {
		cout << "constructing 13" << endl;
		tiles[x][y]->addObject(make_shared<WoundAtk> (make_shared<BasicPotion>(0,"", true, x, y)));
		tiles[x][y]->setOccupy(true);
		++numPotion;
	} else if (input == '5') {
		cout << "constructing 14" << endl;
		tiles[x][y]->addObject(make_shared<WoundDef> (make_shared<BasicPotion>(0,"", true, x, y)));
		tiles[x][y]->setOccupy(true);
		++numPotion;
	} else if (input == 'G') {
		cout << "constructing 15" << endl;
		//f->addGold(getTile(x, y));
		tiles[x][y]->setOccupy(true);
		++numTreasure;
	} else if (input == '6') {
		cout << "constructing 16" << endl;
		tiles[x][y]->addObject(make_shared<Gold>(2, x, y, false));
		tiles[x][y]->setOccupy(true);
		++numTreasure;
	} else if (input == '7') {
		cout << "constructing 17" << endl;
		tiles[x][y]->addObject(make_shared<Gold>(1, x, y, false));
		tiles[x][y]->setOccupy(true);
		++numTreasure;
	} else if (input == '8') {
		cout << "constructing 18" << endl;
		tiles[x][y]->addObject(make_shared<Gold>(4, x, y, false));
		tiles[x][y]->setOccupy(true);
		++numTreasure;
	} else if (input == '9') {
		cout << "constructing 19" << endl;
		tiles[x][y]->addObject(make_shared<Gold>(6, x, y, true));
		tiles[x][y]->setOccupy(true);
		//
		// come back to this tomorrow: how to attach to Dragon! especially
		// if Dragon spawns before or after?
		++numTreasure;
	}

}

void Floor::oneChamber(int id, shared_ptr<Tile> t) {
	if (t->getType() == 0 &&
		t->getChamberID() == 0) {
			(chambers.back())->addTile(t);
			t->setChamberID(id);
			//cout << t->getChamberID() << endl;
			oneChamber(id, t->getNeighbr(1));
			oneChamber(id, t->getNeighbr(2));
			oneChamber(id, t->getNeighbr(3));
			oneChamber(id, t->getNeighbr(4));
			oneChamber(id, t->getNeighbr(5));
			oneChamber(id, t->getNeighbr(6));
			oneChamber(id, t->getNeighbr(7));
	}
}

void Floor::constructChamber(int id) {
	bool found = false;
	chambers.emplace_back(make_shared<Chamber> (id));
	for (int i = 0; i < 25; ++i) {
		for (int j = 0; j < 79; ++j) {
			if (tiles[i][j]->getType() == 0 &&
				tiles[i][j]->getChamberID() == 0) {
				found = true;
				//cout << "run oneChamber for " << i << " " << j << endl;
				oneChamber(id, tiles[i][j]);
				break;
			}
		}
		if (found == true) break;
	}
}

void Floor::constructFloor(istream &input, int start) {
	string line;

	// construct all Tiles accordingly
	tiles.resize(25);
	for (int i = 0; i < 25; ++i) {
		tiles[i].resize(79);
		getline(input, line);
		//cout << line << endl;
		for (int j = 0; j < 79; ++j) {
			if (line[j] == '|') {
				tiles[i][j] = make_shared<Wall> ((make_shared<BasicTile> (i, j, *d)), 1);
			} else if (line[j] == ' ') {
				tiles[i][j] = make_shared<None> (make_shared<BasicTile> (i, j, *d));
			} else if (line[j] == '-') {
				tiles[i][j] = make_shared<Wall> ((make_shared<BasicTile> (i, j, *d)), 0);
			} else if (line[j] == '#') {
				tiles[i][j] = make_shared<Passage> (make_shared<BasicTile> (i, j, *d));
			} else if (line[j] == '+') {
				tiles[i][j] = make_shared<Door> (make_shared<BasicTile> (i, j, *d));
			} else if (line[j] == '@') {
				hasPlayer = true;
				tiles[i][j] = make_shared<BasicTile> (i, j, *d);
				//f->addPC(*(tiles[i][j]));
				player = (tiles[i][j]->getPC());
			} else if (line[j] == 92) {
				hasStairs = true;
				tiles[i][j] = make_shared<Stairs> (make_shared<BasicTile> (i, j, *d));
			} else {
				tiles[i][j] = make_shared<BasicTile> (i, j, *d);
			}
		}
	}

	//cout << "basic floor constructed" << endl;

	//cout << "objects from file spawned" << endl;

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

	//cout << "neighbour setup completed" << endl;

	// construct chamber;
	for (int i = 1; i <= numChambers; ++i) {
		constructChamber(i);
	}

	//cout << "chamber construction completed" << endl;

	// display setup
	d->defaultFloor();
	//cout << &d << endl;

	// add all other Objects
	input.clear();
	input.seekg(start, ios::beg);
	for (int i = 0; i < 25; ++i) {
		getline(input, line);
		for (int j = 0; j < 79; ++j) {
			//cout << "tracker" << endl;
			if (line[j] == '|' ||
				line[j] == ' ' ||
				line[j] == '-' ||
				line[j] == '#' ||
				line[j] == '.' ||
				line[j] == '@' ||
				line[j] == 92) {
				continue;
			} else {
				//cout << "next object is " << line[j] << endl;
				Floor::constructObject(i, j, line[j]);
			}
		}
	}

	//cout << "all completed except spawn" << endl;

	// spawning all Objects necessary for one Floor
	spawnPC();
	//cout << "player spawned" << endl;
	spawnStairs();
	//cout << "stairs spawned" << endl;
	spawnEnemy();
	//cout << "enemy spawned" << endl;
	spawnPotion();
	//cout << "potions spawned" << endl;
	spawnTreasure();
	//cout << "treasure spawned" << endl;

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
