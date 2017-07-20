#ifndef _ITEM_H_
#define _ITEM_H_

#include "object.h"

class PC;
class NPC;

class Item: public Object {
protected:
	int value; // the value (in gold) of an Item

public:
	// constructor and destructor
	Item(int value, int x, int y);
	virtual ~Item()=0;

	// accessors and mutators
	int getValue();
	void setValue(int value);

	// other methods
	virtual void useItem(PC &pc);
};

#endif
