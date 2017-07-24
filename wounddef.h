#ifndef _WOUNDDEF_H_
#define _WOUNDDEF_H_

#include "potiondecorator.h"
#include "basicpotion.h"
#include <string>

class WoundDef: public PotionDecorator {
	int defense;

public:
	// constructor and destructor
	WoundDef(std::shared_ptr<BasicPotion> base);
	~WoundDef();

	// accessors and mutators
	bool getLifetime() override;
	void resetEffect(PC &pc) override;
	int getDefense();


	// other methods
	void useItem(PC &pc) override;
};

#endif
