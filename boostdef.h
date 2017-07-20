#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_

#include "potiondecorator.h"
#include "basicpotion.h"

class BoostDef: public PotionDecorator {
	int defense;

public:
	// constructor and destructor
	BoostDef(int health, BasicPotion *base);
	~BoostDef();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect() override;
	int getDefense();


	// other methods
	void useItem(PC &pc) override;
}

#endif
