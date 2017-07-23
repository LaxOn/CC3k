#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>
#include "character.h"

class PC;
class Gold;

class NPC: public Character{
	bool hostile = false;
	bool canMove = true;
	Gold *loot;
 public:
 	void move();
 	void turnHostile();
 	void cannotMove();
 	void addLoot(int money);
 	//overload == ????
 	virtual void notify(PC &whoNotified)=0;
 	virtual void attack(PC &player)=0;
 	NPC();
 	virtual ~NPC()=0;
};

#endif
