#ifndef ELFNPC_H
#define ELFNPC_H
#include "npc.h"

class PC;
class Tile;

class ElfNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void nextTurn() override;
	ElfNPC(int x, int y, Tile *t);
	~ElfNPC();
};

#endif
