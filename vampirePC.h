#ifndef VAMPIREPC_H
#define VAMPIREPC_H
#include "pc.h"

struct Info;

class VampirePC: public PC {
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	VampirePC(int x, int y);
	~VampirePC();
};

#endif
