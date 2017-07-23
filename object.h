#ifndef OBJECT_H
#define OBJECT_H

class Tile;
class Info;

class Object {
	int x, y;
	char charDisp;
	Tile *address;
 public:
	void setCoords(int x, int y);
	void setDisp(char charDisp);
	void setTile(Tile *t); // include x and y
 	Info getInfo();
 	bool isNear(Info PCInfo, Info NPCInfo);
	Object();
	virtual ~Object()=0;
};

// personal notes
	// put const
	// put override
	// remove weaknessList
	// remove ability
	// possibilty to implement attack in concrete level


// Tile's obj is a vector of 1 or 2 object/s



// pocket didn't exist
	// cna make a vector of a pocket

// death
// checked
	// after attack
	// calls iDied()
		// call tile's add item and move the loot
		// calls tile delete the npc
		// Tile pops char
	// afer potion


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



#endif
