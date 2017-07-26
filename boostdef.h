#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_

#include "potiondecorator.h"
#include "basicpotion.h"
#include <string>

class BoostDef: public PotionDecorator {
	int defense;

public:
	// constructor and destructor
	BoostDef(std::shared_ptr<BasicPotion> base);
	~BoostDef();

	// accessors and mutators
	bool getLifetime() override;
	int getDefense();


	// other methods
	void useItem(PC &pc) override;
};

#endif
