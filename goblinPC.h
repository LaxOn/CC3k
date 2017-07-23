#ifndef GOBLINPC_H
#define GOBLINPC_H
#include <memory>
#include "pc.h"

struct Info;
class Tile;
class Display;

class GoblinPC: public PC {
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	GoblinPC(int x, int y, Tile *t,
		std::shared_ptr<Display> D);
	~GoblinPC();
};

#endif
