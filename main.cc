#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "game.h"
#include "floor.h"

using namespace std;

int main() {
	ifstream floorplaninput{"default-floor.txt"};

	// test block
	//string columns;
	//getline(floorplaninput, columns);
	//cout << columns.length() <<endl;
	// end test block

	auto current_game = make_unique<Game> (floorplaninput);

	current_game->displayFloor(1);
	
	return 0;
}
