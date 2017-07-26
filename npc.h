#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>
#include "character.h"

class PC;
class Gold;
class Tile;
class Display;

class NPC: public Character{
	bool canMove = true;
	int loot = 0;
	bool attackPC = false;
 protected:
	Tile *goldTile = nullptr;
 public:
 	bool pcInRange();
 	void guardGold(Tile &goldTile);
 	Tile *getGold();
 	void justAttacked();
 	void willAttack();
 	void move(Display &D);
 	void cannotMove();
 	void freeze(bool b);
 	void addLoot(int money);
 	int getLoot();
 	virtual void turnHostile();
 	virtual void notify(PC &whoNotified)=0;
 	virtual void attack(PC &player)=0;
 	NPC();
 	virtual ~NPC()=0;
};

#endif
