#ifndef DRAGONNPC_H
#define DRAGONNPC_H
#include "npc.h"

class PC;
class Tile;

class DragonNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void nextTurn() override;
	DragonNPC(int x, int y, Tile *t);
	~DragonNPC();
};

#endif
