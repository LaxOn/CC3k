#ifndef _POTION_H_
#define _POTION_H_

#include "item.h"
#include <string>

class Potion: public Item {
	std::string effect;

protected:
	bool lifetime;

public:
	// constructor and destructor
	Potion();
	virtual ~Potion()=0;

	// accessors and mutators
	std::string getEffect();
	void setEffect(std::string effect);
	virtual bool getLifetime();

	// other methods
	void allowPickup() override;
	void useItem(PC &pc) override;
};

#endif
