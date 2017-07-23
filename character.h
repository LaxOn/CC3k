#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "object.h"

class Character: public Object {
	int hp, atk, def;
	std::string type;
	int potionMult = 1;
	int hpMax = 0;
	int ceil(float num);
 public:
	void setStats(int hp, int atk, int def);
	void setType(std::string type);
	void setMaxHP(int max);
	void setPotionMult(int max);
	void changeHP(int num, bool forPotion);
	void changeAtk(int num);
	void changeDef(int num);
	int getHP();
	int getAtk();
	int getDef();
	int calcDmg(int atk, int def);
	std::string getType();
 	virtual void nextTurn()=0;
	Character();
	virtual ~Character()=0;
};

#endif
