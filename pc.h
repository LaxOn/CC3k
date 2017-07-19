#ifndef PC_H
#define PC_H
#include "character.h"

class Potion;
class NPC;
class Display;
class Gold;

class PC: public Character{
  	std::vector<NPC*> NPCs;
  	int numNPCs = 0;
  	Display *disp = nullptr;
	Potion *item = nullptr;
	int money = 0;
 public:
	void useItem();
	// item->useItem(*this)
	void pickUpItem(Potion *item);
	void getGold(Gold &gold);
	void move(char dir);
	void attach(NPC* ob);
	void detach(NPC* ob);
	void notifyNPCs();
	void attach(Display *disp);
	void notifyDisplay();
 	virtual void attack(NPC& enemy)=0;
 	virtual void defendFrom(NPC& enemy)=0;
 	virtual void nextTurn()=0;
 	PC();
 	virtual ~PC()=0;
};

#endif
