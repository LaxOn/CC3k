#ifndef HUMANNPC_H
#define HUMANNPC_H
#include "npc.h"

class PC;

class HumanNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override; // no defendFrom as PC implements it
 	void nextTurn() override;
	HumanNPC(int x, int y);
	~HumanNPC();
};

#endif
