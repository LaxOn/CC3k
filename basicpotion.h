#ifndef _BASICPOTION_H_
#define _BASICPOTION_H_

#include "Potion.h"

class BasicPotion: public Potion {

public:
	// constructor and destructor
	BasicPotion(int value, string effect, bool life, int x, int y);
	~BasicPotion();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect() override;

	// other methods
	void useItem(PC &pc) override;
};

#endif
