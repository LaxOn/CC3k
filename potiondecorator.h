#ifndef _POTIONDECORATOR_H_
#define _POTIONDECORATOR_H_

#include <memory>
#include "potion.h"
#include "basicpotion.h"

class PotionDecorator: public Potion {
protected:
	std::shared_ptr<BasicPotion> base;

public:
	// constructor and destructor
	PotionDecorator(std::shared_ptr<BasicPotion> base);
	virtual ~PotionDecorator();
};

#endif
