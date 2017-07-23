#include "potiondecorator.h"

using namespace std;

PotionDecorator::PotionDecorator(shared_ptr<BasicPotion> base) :
	base{base} {}

PotionDecorator::~PotionDecorator() {}
