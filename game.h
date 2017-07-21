#ifndef GAME_H
#define GAME_H

class Dungeon;

class Game {
	int curFloor;
	Dungeon *gameDungeon;
	void near();
 public:
 	void displayFloor(int floor);
 	void nextTurn();
 	void spawn(int x, int y, std::string);
 	Game();
 	~Game();
}

#endif