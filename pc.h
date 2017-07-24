#ifndef PC_H
#define PC_H
#include <vector>
#include <memory>
#include "character.h"

class Potion;
class NPC;
class Display;
class Gold;

class PC: public Character{
  	std::vector<std::shared_ptr<NPC>> NPCs;
  	int numNPCs = 0;
  	std::shared_ptr<Display> D;
	int money = 0;
 public:
	void useItem(int dir);
	int getMoney();
	void addMoney(int money);
	void move(int dir);
	void attach(std::shared_ptr<NPC> ob);
	void detach(std::shared_ptr<NPC> ob);
	void notifyNPCs();
	void attach(std::shared_ptr<Display> D);
	void notifyDisplay();
 	virtual void attack(NPC& enemy)=0;
 	virtual void defendFrom(NPC& enemy)=0;
 	PC();
 	virtual ~PC()=0;
};

#endif
