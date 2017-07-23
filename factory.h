#ifndef GTOR_H
#define GTOR_H
#include <memory>
using namespace std;

class Display;
class Tile;

class Factory {
	std::shared_ptr<Display> D;
 public:
	int randInt(int range);
	void addEnemy(Tile &t);
	void addDragon(Tile &t);
	void addMercant(Tile &t);
	void addPC(Tile &t, char race);
	Factory(shared_ptr<Display> D);
	~Factory();
};

#endif
