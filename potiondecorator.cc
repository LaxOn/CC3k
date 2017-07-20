#include "potiondecorator.h"

using namespace std;

PotionDecorator::PotionDecorator(BasicPotion * base) :
	base{base};

PotionDecorator::~PotionDecorator() {
	delete base;
}
