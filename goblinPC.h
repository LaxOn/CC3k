#ifndef GOBLINPC_H
#define GOBLINPC_H
#include "pc.h"

struct Info;

class GoblinPC: public PC{
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	GoblinPC();
	~GoblinPC();
};

#endif
