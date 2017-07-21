#ifndef DROWPC_H
#define DROWPC_H
#include "pc.h"

struct Info;

class DrowPC: public PC{
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	DrowPC(int x, int y);
	~DrowPC();
};

#endif
