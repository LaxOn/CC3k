#ifndef GAME_CC
#define GAME_CC
#include <iostream>
#include <string>
#include "game.h"
#include "dungeon.h"

void Game::displayFloor(Dungeon &dung, int floor) {
	std::cout << gameDungeon->getFloor(floor);
}

void Game::nextTurn() {
	// don't know fully yet
	// call all next turn of PC
		// special ability
	// call next turn of nPC
		// moves all NPC randomly
		// attack PC if it's near PC
}

void Game::spawn(int x, int y, std::string) {
	// call spawn on a floor
		// call constructor of the object with that string name
}

Game::Game() {
	curFloor = 1;
	// constructs the dungeons
	gameDungeon = std::make_unique<Dungeon>(5) // put args of the constructor of dungeon in the parenthesis)
	gameDungeon->constructFloor();
}

Game::~Game() {}

#endif