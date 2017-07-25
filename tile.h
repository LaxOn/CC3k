#ifndef _TILE_H_
#define _TILE_H_
#include <vector>
#include <memory>
#include <string>

#include "item.h"
#include "info.h"

class Object;
class Tile;
class Display;
class NPC;
class PC;

class Tile {
	int x;
	int y;

	bool occupy;
	bool dragonHoard;

	bool sideWall;

	int chamberID = 0; // identifies which Chamber this Tile is in.

protected:
	Display *d;
	std::vector<Tile *> neighbours;
	std::shared_ptr<Item> obj;
	std::shared_ptr<PC> PCobj;
	std::shared_ptr<NPC> NPCobj;

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

	void setDisplay(Display &d);

	bool getSideWall();
	void setSideWall(bool b);

	int getChamberID();
	void setChamberID(int id);

	void stealNPC(Tile *t);
	void stealPC(Tile *t);
	void useItemOn(int dir, PC &pc);
	void moveObj(int dir);
	void useItemTo(PC &pc);
	void resetItem();
	void resetPC();
	void resetNPC();

	void addNPC(std::shared_ptr<NPC> npc);
	std::shared_ptr<NPC> getNPC();

	void addPC(std::shared_ptr<PC> pc);
	std::shared_ptr<PC> getPC();
	
	virtual std::shared_ptr<Item> & getObject();
	virtual Tile *getNeighbr(int index);

	// other methods

	virtual void addObject(std::shared_ptr<Item> o);
	virtual void addNeighbr(Tile *t);
	virtual void killObject();
	virtual int getType();
};

#endif
