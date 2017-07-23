#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "game.h"
#include "floor.h"

using namespace std;

int main() {
	// setting up file input
	ifstream floorplaninput{"default-floor.txt"};

	// making new Game object
	auto current_game = make_unique<Game> (floorplaninput);

	// testing display
	current_game->displayFloor(1);
	current_game->displayFloor(2);
	current_game->displayFloor(3);
	current_game->displayFloor(4);
	current_game->displayFloor(5);
	
	return 0;
}
