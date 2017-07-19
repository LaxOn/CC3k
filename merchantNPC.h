#ifndef MERCHANTNPC_H
#define MERCHANTNPC_H
#include "npc.h"

class PC;

class MerchantNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void defendFrom(PC &player) override;
 	void nextTurn() override;
	MerchantNPC();
	~MerchantNPC();
};

#endif
