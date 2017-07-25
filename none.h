#ifndef _NONE_H_
#define _NONE_H_

#include "tiledecorator.h"

class None: public TileDecorator {

public:
	// constructor and destructor
	None(std::shared_ptr<BasicTile> base);
	~None();

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
