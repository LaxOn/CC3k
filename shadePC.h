#ifndef SHADEPC_H
#define SHADEPC_H
#include "pc.h"

struct Info;

class ShadePC: public PC {
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	ShadePC(int x, int y);
	~ShadePC();
};

#endif
