#ifndef ELFNPC_H
#define ELFNPC_H
#include "npc.h"

class PC;

class ElfNPC: public NPC{
 public:
 	void notify(PC &whoNotified) override;
 	void attack(PC &player) override;
 	void defendFrom(PC &player) override;
 	void nextTurn() override;
	ElfNPC();
	~ElfNPC();
};

#endif
