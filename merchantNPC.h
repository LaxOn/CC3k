#ifndef MERCHANTNPC_H
#define MERCHANTNPC_H
#include "npc.h"

class PC;
class Tile;

class MerchantNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override; // no defendFrom as PC implements it
 	void nextTurn() override;
	MerchantNPC(int x, int y, Tile *t);
	~MerchantNPC();
};

#endif
