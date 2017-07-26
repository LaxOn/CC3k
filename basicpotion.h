#ifndef _BASICPOTION_H_
#define _BASICPOTION_H_

#include "potion.h"
#include <string>

class BasicPotion: public Potion {

public:
	// constructor and destructor
	BasicPotion(int value, std::string effect, bool lifetime, int x, int y);
	~BasicPotion();

	// accessors and mutators
	bool getLifetime() override;

	// other methods
	void useItem(PC &pc) override;
};

#endif
