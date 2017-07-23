#include "display.h"
#include "tile.h"
#include "pc.h"

using namespace std;

// constructor and destructor
Display::Display() {}
	
Display::~Display() {}

// accessor and mutator
void Display::setFloor(Floor *f) {
	this->f = f;
}

string Display::getRace() {
	return race;
}

void Display::setRace(PC &pc) {
	race = pc.getType();
}

int Display::getHP() {
	return hp;
}

void Display::setHP(PC &pc) {
	hp = pc.getHP();
}

int Display::getAtk() {
	return atk;
}

void Display::setAtk(PC &pc) {
	atk = pc.getAtk();
}

int Display::getDef() {
	return def;
}

void Display::setDef(PC &pc) {
	def = pc.getDef();
}

int Display::getGold() {
	return gold;
}

void Display::setGold(PC &pc) {

}

string Display::getAction() {
	return action;
}

void Display::setAction(string act) {

}

int Display::getFloorNum() {
	return floorNum;
}

void Display::setFloorNum(Floor *f) {
	floorNum = f->getPosition();
}

// other methods
void Display::defaultFloor() {
	board.resize(25);
	for (int i = 0; i < 25; ++i) {
		board[i].resize(79);
		for (int j = 0; j < 79; ++j) {
			if ((f->getTile(i, j))->getType() == 0) {
				board[i][j] = '.';
			} else if ((f->getTile(i, j))->getType() == 1) {
				board[i][j] = '#';
			} else if ((f->getTile(i, j))->getType() == 2) {
				board[i][j] = 92;
			} else if ((f->getTile(i, j))->getType() == 3) {
				board[i][j] = '+';
			} else if ((f->getTile(i, j))->getType() == 4 
						&& (f->getTile(i, j))->getSideWall() == 1) {
				board[i][j] = '|';
			} else if ((f->getTile(i, j))->getType() == 4 
						&& (f->getTile(i, j))->getSideWall() == 0){
				board[i][j] = '-';
			} else if ((f->getTile(i, j))->getType() == 5) {
				board[i][j] = ' ';
			}
		}
	}
}

void Display::displayFloor() {
	for (int i = 0; i < 25; ++i) {
		for (int j = 0; j < 79; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void Display::displayStats() {
	cout << "Floor: " << floorNum << endl;
	cout << "Race: " << race << " Gold: " << gold << endl;
	cout << "HP: " << hp << endl;
	cout << "Atk: " << atk << endl;
	cout << "Def: " << def << endl;
	cout << "Action: " << action << endl;
}
	
void Display::update(Tile &, std::string str) {
	// to be implemented later
}

void Display::update(PC *pc) {
	// to be implemented later
}

ostream &operator<<(ostream &out, Display &d) {
	d.displayFloor();
	d.displayStats();
	return out;
}