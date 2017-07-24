#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>

#include "game.h"
#include "floor.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand(time(0));

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

	string race = "s";

	// making new Game object
	auto current_game = make_unique<Game> (floorplaninput, race);

	// testing display
	current_game->displayFloor(1);
	
	cout << "MAIN() FINISHED" << endl;
	return 0;
}
