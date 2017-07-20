#include "floor.h"

using namespace std;

// constructor and destructors
Floor(int position);
~Floor();

// accessors and mutators
shared_ptr<Chamber> *& getChamber(int index);
shared_ptr<Tile> *& getTile(int x, int y);
shared_ptr<Stairs> *& getStairs(int index);

shared_ptr<NPC> *& getNPC(int index);
shared_ptr<Potion> *& getPotion(int index);
shared_ptr<Gold> *& getGold(int index);

shared_ptr<PC> *& getPlayer();

int getPosition();

// other methods
void constructFloor();
void constructFloor(istream &input, int start);
void display();

void &operator<<(ostream &out, const Floor &f);
