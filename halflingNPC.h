#ifndef HALFLINGNPC_H
#define HALFLINGNPC_H
#include "npc.h"

class PC;

class HalflingNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override; // no defendFrom as PC implements it
 	void nextTurn() override;
	HalflingNPC(int x, int y);
	~HalflingNPC();
};

#endif
