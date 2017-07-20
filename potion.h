#ifndef _POTION_H_
#define _POTION_H_

#include "item.h"

class Potion: public Item {
	std::string effect;

protected:
	bool lifetime;

public:
	// constructor and destructor
	Potion(int value, string effect, bool life, int x, int y);
	virtual ~Potion()=0;

	// accessors and mutators
	std::string getEffect();
	void setEffect(std::string effect);
	virtual bool getLifetime();
	virtual void resetEffect();

	// other methods
	void useItem(PC &pc) override;
};

#endif
