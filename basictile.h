#ifndef _BASICTILE_H_
#define _BASICTILE_H_

#include "tile.h"

class BasicTile: public Tile {
	// numbers will be used to represent the type of Tile:
	// 0 for BasicTile
	// 1 for Passage
	// 2 for Stairs
	// 3 for Door
	// 4 for Wall
	// 5 for None

public:
	// constructor and destructor
	BasicTile(int x, int y, Display &dply);
	~BasicTile();

	// accessors and mutators
	std::shared_ptr<Item> & getObject() override;
	Tile *getNeighbr(int index) override;

	// other methods
	void addObject(std::shared_ptr<Item> o) override;
	void addNeighbr(Tile *t) override;
	void killObject() override;
	int getType() override;
};

#endif
