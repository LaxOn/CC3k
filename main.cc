#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "dungeon.h"
#include "floor.h"

using namespace std;

int main() {
	ifstream floorplaninput{"default-floor.txt"};
	auto dungeon = make_shared<Dungeon> (5);

	dungeon->constructFloor(floorplaninput);

	cout << dungeon->getFloor(1) << endl;
	
	return 0;
}
