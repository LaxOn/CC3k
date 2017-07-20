#ifndef _POTIONDECORATOR_H_
#define _POTIONDECORATOR_H_

#include "Potion.h"
#include "BasicPotion.h"

class PotionDecorator: public Potion {
	BasicPotion * base;

public:
	// constructor and destructor
	PotionDecorator(BasicPotion * base);
	virtual ~PotionDecorator();
};

#endif
