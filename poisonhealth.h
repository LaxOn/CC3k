#ifndef _POISONHEALTH_H_
#define _POISONHEALTH_H_

#include "potiondecorator.h"
#include "basicpotion.h"

class PoisonHealth: public PotionDecorator {
	int health;

public:
	// constructor and destructor
	PoisonHealth(int health, BasicPotion *base);
	~PoisonHealth();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect() override;
	int getHealth();


	// other methods
	void useItem(PC &pc) override;
}

#endif