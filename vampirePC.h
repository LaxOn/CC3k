#ifndef VAMPIREPC_H
#define VAMPIREPC_H
#include <memory>
#include "pc.h"

struct Info;
class Tile;
class Display;

class VampirePC: public PC {
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	VampirePC(int x, int y, Tile *t,
		std::shared_ptr<Display> D);
	~VampirePC();
};

#endif
