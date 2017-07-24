#ifndef FACTORY_H
#define FACTORY_H
#include <memory>
#include <string>
using namespace std;

class Display;
class Tile;
class PC;

class Factory {
	Display *D;
	std::shared_ptr<PC> player;
 public:
	int randInt(int max);
	void addEnemy(Tile &t);
	void addDragon(Tile &t);
	void addGold(Tile &t);
	void addPC(Tile &t, std::string race);
	void addPotion(Tile &t);
	Factory();
	Factory(Display &D);
	~Factory();
};

#endif
