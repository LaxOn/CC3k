#ifndef _TILEDECORATOR_H_
#define _TILEDECORATOR_H_

#include "tile.h"
#include "basictile.h"

class TileDecorator: public Tile {
protected:
	std::shared_ptr<BasicTile> base;

public:
	// constructor and destructor
	TileDecorator(std::shared_ptr<BasicTile> base);
	~TileDecorator();
};

#endif
