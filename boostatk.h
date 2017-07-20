#ifndef _BOOSTATK_H_
#define _BOOSTATK_H_

#include "potiondecorator.h"
#include "basicpotion.h"

class BoostAtk: public PotionDecorator {
	int attack;

public:
	// constructor and destructor
	BoostAtk(int health, BasicPotion *base);
	~BoostAtk();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect() override;
	int getAttack();


	// other methods
	void useItem(PC &pc) override;
}

#endif
