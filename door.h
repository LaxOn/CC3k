#ifndef _DOOR_H_
#define _DOOR_H_

#include "tiledecorator.h"

class Door: public TileDecorator {

public:
	// constructor and destructor
	Door(std::shared_ptr<BasicTile> base);
	~Door();

	// accessors and mutators
	std::shared_ptr<Item> & getObject() override;
	std::shared_ptr<Tile> & getNeighbr(int index) override;

	// other methods
	void addObject(std::shared_ptr<Item> o) override;
	void addNeighbr(std::shared_ptr<Tile> t) override;
	void killObject() override;
	void moveObj(int direction) override;
	int getType() override;
};

#endif
