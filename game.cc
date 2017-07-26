#ifndef GAME_CC
#define GAME_CC

#include <iostream>
#include <string>
#include "game.h"
#include "pc.h"
#include "npc.h"
#include "dungeon.h"
#include "slap.h"
#include "tile.h"
#include "floor.h"

using namespace std;

// constructor and destructor
Game::Game(std::istream &input, string race) :
	input{input} {
	curFloor = 1;
	// constructs the dungeons
	gameDungeon = make_unique<Dungeon> (5, this, input); // put args of the constructor of dungeon in the parenthesis)
	gameDungeon->constructFloor(race);
}

Game::~Game() {}

void Game::pcMove(int dir) {
	std::shared_ptr<Floor> f = gameDungeon->getFloor(curFloor);
	std::shared_ptr<PC> pc = f->getPlayer();
	pc->move(dir);
}

void Game::pcUse(int dir) {
	std::shared_ptr<Floor> f = gameDungeon->getFloor(curFloor);
	std::shared_ptr<PC> pc = f->getPlayer();
	pc->useItem(dir);
}

void Game::pcAtk(int dir) {
	std::shared_ptr<Floor> f = gameDungeon->getFloor(curFloor);
	std::shared_ptr<PC> pc = f->getPlayer();
	pc->attackDir(dir);
}

void Game::switchFloor(int floor){
	curFloor = floor;
}

// accessors and mutators
int Game::getCurFloor(){
	return curFloor;
}

// other methods
void Game::displayFloor(int floor) {
	cout << *(gameDungeon->getFloor(floor));
}

void Game::nextTurn() {
	
	std::shared_ptr<Floor> f = gameDungeon->getFloor(curFloor);
	std::shared_ptr<PC> pc = f->getPlayer();
	Display *D = pc->getDisplay();
	for (int j=0; j<=78; ++j) {
		for (int i=0; i<=24; ++i) {
			std::shared_ptr<Tile> t = f->getTile(i, j);
			if (t->getNPC()) {
				std::shared_ptr<NPC> npc = t->getNPC();
				if (npc->pcInRange()) {
					npc->attack(*pc);
					D->setHP(*pc);
				} else npc->move(*D);
				npc->justAttacked();
				npc->notify(*pc);
			}
		}
	}
	if (pc->getHP() <= 0) throw Slap("You died. Game over... ");
}

void Game::freezeEnemy(bool canMove) {
	std::shared_ptr<Floor> f = gameDungeon->getFloor(curFloor);
	std::shared_ptr<PC> pc = f->getPlayer();
	for (int j=0; j<=78; ++j) {
		for (int i=0; i<=24; ++i) {
			std::shared_ptr<Tile> t = f->getTile(i, j);
			if (t->getNPC()) {
				std::shared_ptr<NPC> npc = t->getNPC();
				npc->freeze(canMove);
			}
		}
	}
}

void Game::descend() {
	++curFloor;
}

#endif