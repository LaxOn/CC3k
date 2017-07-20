#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include "floor.h"

class Dungeon {
	int size;
	Floor * floors; // array of pointers to Floors on the heap

public:
	// constructor and destructor
	Dungeon(int size);
	~Dungeon();

	// accessors and mutators
	int getSize();
	Floor *& getFloor(int whichFloor);

	// other methods
	void constructFloor();
}

#endif
