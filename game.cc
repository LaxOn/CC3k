#ifndef GAME_CC
#define GAME_CC

#include <iostream>
#include <string>
#include "game.h"
#include "dungeon.h"

using namespace std;

// constructor and destructor
Game::Game(std::istream &input, string race) :
	input{input} {
	curFloor = 1;
	// constructs the dungeons
	gameDungeon = make_unique<Dungeon> (5); // put args of the constructor of dungeon in the parenthesis)
	gameDungeon->constructFloor(input, curFloor, race);
	cout << "GAME CONSTRUCTION COMPLETE" << endl;
}

Game::~Game() {}

// accessors and mutators
int Game::getCurFloor(){
	return curFloor;
}

// other methods
void Game::displayFloor(int floor) {
	cout << *(gameDungeon->getFloor(floor));
}

void Game::nextTurn() {
	// don't know fully yet
	// call all next turn of PC
		// special ability
	// call next turn of nPC
		// moves all NPC randomly
		// attack PC if it's near PC
}

void Game::spawn(int x, int y, std::string str) {
	// call spawn on a floor
		// call constructor of the object with that string name
}

#endif