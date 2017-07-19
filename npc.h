#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>
#include "character.h"

class Gold;

class NPC: public Character{
	bool hostile = false;
	bool canMove = true;
	Gold *loot;
 public:
 	void move();
 	// calls Tile it currently in wiht the directions to go
 	// TIle call the neighbour
 	// set Nieghtnours ptr to character
 	// oldTIle = nullptr
 	// newTile call character with itself
 	void turnHostile();
 	void cannotMove();
 	void addLoot(int money);
 	//overload == ????
 	virtual void notify(PC &whoNotified)=0;
 	virtual void attack(PC &player)=0;
 	virtual void defendFrom(PC &player)=0;
 	NPC();
 	virtual ~NPC()=0;
};

#endif
