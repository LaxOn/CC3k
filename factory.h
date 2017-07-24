#ifndef FACTORY_H
#define FACTORY_H
#include <memory>
using namespace std;

class Display;
class Tile;
class PC;

class Factory {
	std::shared_ptr<Display> D;
	std::shared_ptr<PC> player;
 public:
	int randInt(int max);
	void addEnemy(Tile &t);
	void addDragon(Tile &t);
	void addPC(Tile &t, char race);
	void addPotion(Tile &t);
	Factory(shared_ptr<Display> D);
	~Factory();
};

#endif
