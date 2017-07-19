#ifndef DRAGONNPC_H
#define DRAGONNPC_H
#include "npc.h"

class PC;

class DragonNPC: public NPC{
	Tile *goldAddress;
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void defendFrom(PC &player) override;
 	void nextTurn() override;
	DragonNPC(int x, int y, Tile *t, Gold *g);
	~DragonNPC();
};

#endif
