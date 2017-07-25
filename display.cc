#include "display.h"
#include "tile.h"
#include "pc.h"
#include "info.h"

using namespace std;

// constructor and destructor
Display::Display() :
	race{""}, hp{0}, atk{0}, def{0}, gold{0}, action {""} {}
	
Display::~Display() {}

// accessor and mutator
void Display::setFloor(Floor *f) {
	this->f = f;
}

string Display::getRace() {
	return race;
}

void Display::setRace(PC &pc) {
	string temp = pc.getType();

	race = temp.substr(0, temp.length() - 2);
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
	action = act;
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
				// testing Chamber setup
				/*
				int c_id = (f->getTile(i, j))->getChamberID();
				//cout << c_id << endl;
				if (c_id == 1) {
					board[i][j] = '1';
				} else if (c_id == 2) {
					board[i][j] = '2';
				} else if (c_id == 3) {
					board[i][j] = '3';
				} else if (c_id == 4) {
					board[i][j] = '4';
				} else if (c_id == 5) {
					board[i][j] = '5';
				} else {
					board[i][j] = '.';
				}
				*/
				board[i][j] = '.';
			} else if ((f->getTile(i, j))->getType() == 1) {

				int c_id = (f->getTile(i, j))->getChamberID();
				//cout << c_id << endl;
				if (c_id == 1) {
					board[i][j] = '1';
				} else if (c_id == 2) {
					board[i][j] = '2';
				} else if (c_id == 3) {
					board[i][j] = '3';
				} else if (c_id == 4) {
					board[i][j] = '4';
				} else if (c_id == 5) {
					board[i][j] = '5';
				} else {
					board[i][j] = '#';
				}

				//board[i][j] = '#';
			} else if ((f->getTile(i, j))->getType() == 2) {

				int c_id = (f->getTile(i, j))->getChamberID();
				//cout << c_id << endl;
				if (c_id == 1) {
					board[i][j] = '1';
				} else if (c_id == 2) {
					board[i][j] = '2';
				} else if (c_id == 3) {
					board[i][j] = '3';
				} else if (c_id == 4) {
					board[i][j] = '4';
				} else if (c_id == 5) {
					board[i][j] = '5';
				} else {
					board[i][j] = 92;
				}

				//board[i][j] = 92;
			} else if ((f->getTile(i, j))->getType() == 3) {

				int c_id = (f->getTile(i, j))->getChamberID();
				//cout << c_id << endl;
				if (c_id == 1) {
					board[i][j] = '1';
				} else if (c_id == 2) {
					board[i][j] = '2';
				} else if (c_id == 3) {
					board[i][j] = '3';
				} else if (c_id == 4) {
					board[i][j] = '4';
				} else if (c_id == 5) {
					board[i][j] = '5';
				} else {
					board[i][j] = '+';
				}

				//board[i][j] = '+';
			} else if ((f->getTile(i, j))->getType() == 4 
						&& (f->getTile(i, j))->getSideWall() == 1) {

				int c_id = (f->getTile(i, j))->getChamberID();
				//cout << c_id << endl;
				if (c_id == 1) {
					board[i][j] = '1';
				} else if (c_id == 2) {
					board[i][j] = '2';
				} else if (c_id == 3) {
					board[i][j] = '3';
				} else if (c_id == 4) {
					board[i][j] = '4';
				} else if (c_id == 5) {
					board[i][j] = '5';
				} else {
					board[i][j] = '|';
				}

				//board[i][j] = '|';
			} else if ((f->getTile(i, j))->getType() == 4 
						&& (f->getTile(i, j))->getSideWall() == 0){

				int c_id = (f->getTile(i, j))->getChamberID();
				//cout << c_id << endl;
				if (c_id == 1) {
					board[i][j] = '1';
				} else if (c_id == 2) {
					board[i][j] = '2';
				} else if (c_id == 3) {
					board[i][j] = '3';
				} else if (c_id == 4) {
					board[i][j] = '4';
				} else if (c_id == 5) {
					board[i][j] = '5';
				} else {
					board[i][j] = '-';
				}

				//board[i][j] = '-';
			} else if ((f->getTile(i, j))->getType() == 5) {

				int c_id = (f->getTile(i, j))->getChamberID();
				//cout << c_id << endl;
				if (c_id == 1) {
					board[i][j] = '1';
				} else if (c_id == 2) {
					board[i][j] = '2';
				} else if (c_id == 3) {
					board[i][j] = '3';
				} else if (c_id == 4) {
					board[i][j] = '4';
				} else if (c_id == 5) {
					board[i][j] = '5';
				} else {
					board[i][j] = ' ';
				}

				//board[i][j] = ' ';
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
	
void Display::update(Tile &t, std::string str) {
	//cout << "display update runs" << endl;
	Info temp = t.getInfo();
	int x = temp.x;
	int y = temp.y;
	cout << "this was ran" <<endl;
	//cout << "the object is " << str << endl;
	//cout << x << " " << y << endl;
	//cout << board[x][y] << endl;

	if (str == "ShadePC" || str == "DrowPC" || str == "VampirePC" ||
		str == "TrollPC" || str == "GoblinPC") {
		board[x][y] = '@';
	} else if (str == "HumanNPC") {
		board[x][y] = 'H';
	} else if (str == "DwarfNPC") {
		board[x][y] = 'W';
	} else if (str == "ElfNPC") {
		board[x][y] = 'E';
	} else if (str == "OrcNPC") {
		board[x][y] = 'O';
	} else if (str == "MerchantNPC") {
		board[x][y] = 'M';
	} else if (str == "DragonNPC") {
		board[x][y] = 'D';
	} else if (str == "HalflingNPC") {
		board[x][y] = 'L';
	} else if (str == "P") {
		board[x][y] = 'P';
	} else if (str == "G") {
		board[x][y] = 'G';
	} else if (str == "Stairs") {
		board[x][y] = '\\';
	} else if (str == ".") {
		board[x][y] = '.';					// Bryan added this. Is this okay?
	}
	//cout << board[x][y] << endl;
}

ostream &operator<<(ostream &out, Display &d) {
	d.displayFloor();
	d.displayStats();
	return out;
}