#ifndef HALFLINGNPC_H
#define HALFLINGNPC_H
#include "npc.h"

class PC;

class HalflingNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void defendFrom(PC &player) override;
 	void nextTurn() override;
	HalflingNPC();
	~HalflingNPC();
};

#endif
