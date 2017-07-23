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

	bool sideWall;

	int chamberID = 0; // identifies which Chamber this Tile is in.

protected:
	std::shared_ptr<Display> d;
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
	void setOccupy(bool inp);

	bool getDragonHoard();
	void setDragonHoard(bool inp);

	void setDisplay(std::shared_ptr<Display> dply);

	bool getSideWall();
	void setSideWall(bool b);

	int getChamberID();
	void setChamberID(int id);
	
	virtual std::shared_ptr<Object> & getObject(int index);
	virtual std::shared_ptr<Tile> & getNeighbr(int index);

	// other methods
	virtual void addObject(std::shared_ptr<Object> o);
	virtual void addNeighbr(std::shared_ptr<Tile> t);
	virtual void killObject();
	virtual int getType();
	virtual void moveObj(int direction);
	void notifyDisplay();
};

#endif
