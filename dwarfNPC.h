#ifndef DWARFNPC_H
#define DWARFNPC_H
#include "npc.h"

class PC;

class DwarfNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void defendFrom(PC &player) override;
 	void nextTurn() override;
	DwarfNPC();
	~DwarfNPC();
};

#endif
