#ifndef _WALL_H_
#define _WALL_H_

#include "tiledecorator.h"

class Wall: public TileDecorator {

public:
	// constructor and destructor
	Wall(std::shared_ptr<BasicTile> base, bool sideWall);
	~Wall();

	// accessors and mutators
	std::shared_ptr<Object> & getObject(int index) override;
	std::shared_ptr<Tile> & getNeighbr(int index) override;

	// other methods
	void addObject(std::shared_ptr<Object> o) override;
	void addNeighbr(std::shared_ptr<Tile> t) override;
	void killObject() override;
	void moveObj(int direction) override;
	int getType() override;
};

#endif
