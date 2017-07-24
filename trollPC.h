#ifndef TROLLPC_H
#define TROLLPC_H
#include <memory>
#include "pc.h"

struct Info;
class Tile;
class Display;

class TrollPC: public PC {
 public:
 	void attack(NPC& enemy) override;
 	void defendFrom(NPC& enemy) override;
 	void nextTurn() override;
	TrollPC(int x, int y, Tile *t);
	~TrollPC();
};

#endif
