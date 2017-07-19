#ifndef HUMANNPC_H
#define HUMANNPC_H
#include "npc.h"

class PC;

class HumanNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void defendFrom(PC &player) override;
 	void nextTurn() override;
	HumanNPC();
	~HumanNPC();
};

#endif
