#ifndef _WOUNDATK_H_
#define _WOUNDATK_H_

#include "potiondecorator.h"
#include "basicpotion.h"

class WoundAtk: public PotionDecorator {
	int attack;

public:
	// constructor and destructor
	WoundAtk(std::shared_ptr<BasicPotion> base);
	~WoundAtk();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect(PC &pc) override;
	int getAttack();


	// other methods
	void useItem(PC &pc) override;
};

#endif
