#ifndef _RESTOREHEALTH_H_
#define _RESTOREHEALTH_H_

#include "potiondecorator.h"
#include "basicpotion.h"

class RestoreHealth: public PotionDecorator {
	int health;

public:
	// constructor and destructor
	RestoreHealth(int health, BasicPotion *base);
	~RestoreHealth();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect() override;
	int getHealth();


	// other methods
	void useItem(PC &pc) override;
}

#endif
