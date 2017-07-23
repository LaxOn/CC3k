#ifndef ORCNPC_H
#define ORCNPC_H
#include "npc.h"

class PC;
class Tile;

class OrcNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override; // no defendFrom as PC implements it
 	void nextTurn() override;
	OrcNPC(int x, int y, Tile *t);
	~OrcNPC();
};

#endif
