#ifndef PC_H
#define PC_H
#include <vector>
#include <memory>
#include "character.h"
#include "display.h"

class Potion;
class NPC;
class Gold;

class PC: public Character {
  	std::vector<std::shared_ptr<NPC>> NPCs;
  	int numNPCs = 0;
  	Display *D = nullptr;
	int money = 0;

	Dungeon *dungeon;
 public:
	void useItem(int dir);
	int getMoney();
	void addMoney(int money);
	void move(int dir);
	void attackDir(int dir);
	void attach(std::shared_ptr<NPC> ob);
	void detach(std::shared_ptr<NPC> ob);
	void notifyNPCs();
	void attach(Display &D);
	void setDungeon(Dungeon *d);
	void notifyDisplay(std::string desc="");
	std::string dirToStr(int dir);
	Display *getDisplay();
 	virtual void attack(NPC& enemy)=0;
 	virtual void defendFrom(NPC& enemy)=0;
 	PC();
 	virtual ~PC()=0;
};

#endif


/*
takeNPC(Tile *) {}
takePC(Tile *) {}
t->moveObj(index);
	std::shared_ptr<Tile> nb = getNeighbr(index);
	if (PCobj) {
		nb->takeNPC(this)
	
	} else if (NPCobj) {
	
	}
			 	// calls Tile it currently in with the directions to go
 	// Tile call the neighbour
 	// set Nieghbours ptr to character
 	// oldTIle = nullptr
 	// newTile call character with itself
*/
