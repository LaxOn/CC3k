#ifndef ORCNPC_H
#define ORCNPC_H
#include "npc.h"

class PC;

class OrcNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void defendFrom(PC &player) override;
 	void nextTurn() override;
	OrcNPC();
	~OrcNPC();
};

#endif
