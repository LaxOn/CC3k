#ifndef DRAGONNPC_H
#define DRAGONNPC_H
#include "npc.h"

class PC;
class Tile;

class DragonNPC: public NPC{
	Tile *goldAddress;
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;	// no defendFrom as PC implements it
 	void nextTurn() override;
	DragonNPC(int x, int y, Tile *t);
	~DragonNPC();
};

#endif
