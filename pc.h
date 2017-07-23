#ifndef PC_H
#define PC_H
#include <vector>
#include "character.h"

class Potion;
class NPC;
class Display;
class Gold;

class PC: public Character{
  	std::vector<NPC*> NPCs;
  	int numNPCs = 0;
  	Display *disp = nullptr;
	int money = 0;
 public:
	void useItem(int dir);
	void addMoney(int money);
	void move(int dir);
	void attach(NPC* ob);
	void detach(NPC* ob);
	void notifyNPCs();
	void attach(Display *disp);
	void notifyDisplay();
 	virtual void attack(NPC& enemy)=0;
 	virtual void defendFrom(NPC& enemy)=0;
 	PC();
 	virtual ~PC()=0;
};

#endif
