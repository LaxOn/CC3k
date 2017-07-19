#ifndef TROLLPC_H
#define TROLLPC_H
#include "pc.h"

struct Info;

class TrollPC: public PC{
 public:
 	Info getState();
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	TrollPC();
	~TrollPC();
};

#endif
