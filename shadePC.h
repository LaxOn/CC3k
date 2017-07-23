#ifndef SHADEPC_H
#define SHADEPC_H
#include <memory>
#include "pc.h"

struct Info;
class Tile;
class Display;

class ShadePC: public PC {
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	ShadePC(int x, int y, Tile *t,
		std::shared_ptr<Display> D);
	~ShadePC();
};

#endif
