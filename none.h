#ifndef _NONE_H_
#define _NONE_H_

#include "tiledecorator.h"

class None: public TileDecorator {

public:
	// constructor and destructor
	None(std::shared_ptr<BasicTile> base);
	~None();

	// accessors and mutators
	std::shared_ptr<Object> *& getObject(int index) override;
	std::shared_ptr<Tile> *& getNeighbr(int index) override;

	// other methods
	void addObject(std::shared_ptr<Object> o) override;
	void addNeighbr(std::shared_ptr<Tile> t) override;
	void killObject() override;
	void moveObj(int direction) override;
	int getType() override;
};

#endif
