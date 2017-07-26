#ifndef _RESTOREHEALTH_H_
#define _RESTOREHEALTH_H_

#include "potiondecorator.h"
#include "basicpotion.h"
#include <string>

class RestoreHealth: public PotionDecorator {
	int health;

public:
	// constructor and destructor
	RestoreHealth(std::shared_ptr<BasicPotion> base);
	~RestoreHealth();

	// accessors and mutators
	bool getLifetime() override;
	int getHealth();


	// other methods
	void useItem(PC &pc) override;
};

#endif
