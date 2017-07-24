#ifndef _PASSAGE_H_
#define _PASSAGE_H_

#include "tiledecorator.h"

class Passage: public TileDecorator {

public:
	// constructor and destructor
	Passage(std::shared_ptr<BasicTile> base);
	~Passage();

	// accessors and mutators
	std::shared_ptr<Item> & getObject() override;
	Tile *getNeighbr(int index) override;

	// other methods
	void addObject(std::shared_ptr<Item> o) override;
	void addNeighbr(Tile *t) override;
	void killObject() override;
	void moveObj(int direction) override;
	int getType() override;
};

#endif
