#ifndef DWARFNPC_H
#define DWARFNPC_H
#include "npc.h"

class PC;

class DwarfNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override; // no defendFrom as PC implements it
 	void nextTurn() override;
	DwarfNPC(int x, int y);
	~DwarfNPC();
};

#endif
