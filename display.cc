#include "display.h"

using namespace std;

// constructor and destructor
Display::Display() {}
	
Display::~Display() {}

// accessor and mutator
void Display::setFloor(Floor *f) {
	this->f = f;
}

string Display::getRace() {

}

void Display::setRace(PC &pc) {

}

int Display::getHP() {
	return hp;
}

void Display::setHP(PC &pc) {

}

int Display::getAtk() {
	return atk;
}

void Display::setAtk(PC &pc) {

}

int Display::getDef() {
	return def;
}

void Display::setDef(PC &pc) {

}

string Display::getAction() {
	return Action;
}

void Display::setAction(string act) {

}

int Display::getFloorNum() {
	return floorNum;
}

void Display::setFloorNum(int num) {

}

// other methods
void Display::displayFloor() {
	board.resize(25);
	for (int i = 0; i < 25; ++i) {
		board[i].resize(79);
		for (int j = 0; j < 79; ++j) {
			if (f->getTile[i][j]->getType() == 0) board[i][j] = '.';
			if (f->getTile[i][j]->getType() == 1) board[i][j] = 92;
			if (f->getTile[i][j]->getType() == 2) board[i][j] = '#';
			if (f->getTile[i][j]->getType() == 3) board[i][j] = '+';
			if (f->getTile[i][j]->getType() == 4 && f->getTile[i][j]->getSideWall() == 1) board[i][j] = '|';
			if (f->getTile[i][j]->getType() == 4 && f->getTile[i][j]->getSideWall() == 0) board[i][j] = '-';
			if (f->getTile[i][j]->getType() == 5) board[i][j] = ' ';
		}
	}
}

void Display::displayStats() {
	// to be implemented later
}
	
void Display::update(Tiles &, std::string str) {
	// to be implemented later
}

void Display::update(PC *pc) {
	// to be implemented later
}

ostream &operator<<(ostream &out, Display &d) {
	for (int i = 0; i < 25; ++i) {
		for (int j = 0; j < 79; ++j) {
			out << board[i][j];
		}
		out << endl;
	}
	return out;
}