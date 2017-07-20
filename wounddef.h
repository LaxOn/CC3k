#ifndef _WOUNDDEF_H_
#define _WOUNDDEF_H_

#include "potiondecorator.h"
#include "basicpotion.h"

class WoundDef: public PotionDecorator {
	int defense;

public:
	// constructor and destructor
	WoundDef(int health, BasicPotion *base);
	~WoundDef();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect() override;
	int getDefense();


	// other methods
	void useItem(PC &pc) override;
}

#endif
