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
	Item();
	virtual ~Item()=0;

	// accessors and mutators
	int getValue();
	void setValue(int value);

	virtual bool getDrgn();
	virtual bool getSlain();

	// other methods
	virtual void allowPickup();
	virtual void useItem(PC &pc);
};

#endif
