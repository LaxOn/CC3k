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
	std::shared_ptr<Object> & getObject() override;
	std::shared_ptr<Tile> & getNeighbr(int index) override;

	// other methods
	void addObject(std::shared_ptr<Object> o) override;
	void addNeighbr(std::shared_ptr<Tile> t) override;
	void killObject() override;
	void moveObj(int direction) override;
	int getType() override;
};

#endif
