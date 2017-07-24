#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>

#include "game.h"
#include "floor.h"

using namespace std;

int main(int argc, char* argv[]) {
	// setting up file input
	string fileName;

	if (argc == 1) {
		fileName = "default-floor.txt";
	} else if (argc == 2) {
		istringstream readFloorName{argv[1]};

		readFloorName >> fileName;
	} else {
		cout << "Incorrect number of arguments" << endl;
		return 1;
	}

	ifstream floorplaninput{fileName};

	string testString;

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
