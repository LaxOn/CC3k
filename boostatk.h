#ifndef _BOOSTATK_H_
#define _BOOSTATK_H_

#include "potiondecorator.h"
#include "basicpotion.h"
#include <string>

class BoostAtk: public PotionDecorator {
	int attack;

public:
	// constructor and destructor
	BoostAtk(std::shared_ptr<BasicPotion> base);
	~BoostAtk();

	// accessors and mutators
	bool getLifetime() override;
	int getAttack();


	// other methods
	void useItem(PC &pc) override;
};

#endif
