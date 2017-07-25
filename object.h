#ifndef OBJECT_H
#define OBJECT_H

class Tile;
class Info;

class Object {
	char charDisp;
	Tile *address = nullptr;
 public:
 	
	int x, y;
	void setCoords(int x, int y);
	void setDisp(char charDisp);
	char getDisp();
	void setTile(Tile *t);
	Tile *getTile();
 	Info getInfo();
 	bool isNear(Info PCInfo, Info NPCInfo);
	Object();
	virtual ~Object()=0;
};

// personal notes
	// put const

// pocket didn't exist
	// can make a vector of a pocket


// death
// checked
	// after attack
	// calls iDied()
		// call tile's add item and move the loot
		// calls tile delete the npc
		// Tile pops char
	// after potion


// get gold by
	// walking over
	// steal as goblin

// tile
	// need a function that returns the number of unoccopied neighbours
	// need a vector of 

//npc move
 	// calls Tile it currently in with the directions to go
 	// Tile call the neighbour
 	// set Nieghbours ptr to character
 	// oldTIle = nullptr
 	// newTile call character with itself

// picking up potions
	// PC will call useItem(int dir)
		//call soemthing in the tile which passes PC and direction
	// Tile will calls its neighbour
	// neighbour call potion with PC as the parameter
		
// picking up gold
	// Tile will check if PC and a gold is in itself
	// if yes, Tile will call PC
			// .... ask JUDY later
	// 

// spawning
	// chamber will have a list of unoccupied tiles
	// ask for a number from factory
	// that number converts to a tile
	// calls addEnemy from Factory to a tile

// floor creates display
	// floor gives display to chamber 
	// chamber gives display to factory

#endif
