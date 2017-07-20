#ifndef _TILE_H_
#define _TILE_H_

#include <vector>
#include <memory>
#include <string>
#include "info.h"

class Object;
class Tile;
class Display;

class Tile {
	int x;
	int y;

	bool occupy;
	bool dragonHoard;

	std::shared_ptr<Display> d;

protected:
	std::vector<std::shared_ptr<Object>> obj;
	std::vector<std::shared_ptr<Tile>> neighbours;

public:
	// constructor and destructor
	Tile();
	virtual ~Tile()=0;

	// accessors and mutators
	Info getInfo();
	void setInfo(int x, int y);

	bool getOccupy();
	bool setOccupy(bool inp);

	bool getDragonHoard();
	bool setDragonHoard(bool inp);

	void setDisplay(std::shared_ptr<Display> dply);
	
	virtual shared_ptr<Object> *& getObject(int index);
	virtual shared_ptr<Tile> *& getNeighbr(int index);

	// other methods
	virtual void addObject(shared_ptr<Object> o);
	virtual void addNeighbr(shared_ptr<Tile> t);
	virtual void killObject();
	virtual int getType();
	virtual void moveObj(int direction);
	void notifyDisplay();
}

#endif
