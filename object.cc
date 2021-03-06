#include "object.h"
#include "info.h"

void Object::setCoords(int x, int y) {
		this->x = x;
		this->y = y;	
}

void Object::setDisp(char charDisp) {
	this->charDisp = charDisp;	
}

char Object::getDisp() {
	return charDisp;	
}

void Object::setTile(Tile *t) {
	address = t;
}

Tile *Object::getTile() {
	return address;
}

Info Object::getInfo() {
	// call constructor for Info
	return Info{x,y};
}

bool Object::isNear(Info PCInfo, Info NPCInfo) {
	int NPCx = NPCInfo.x;
	int NPCy = NPCInfo.y;
	int PCx = PCInfo.x;
	int PCy = PCInfo.y;
	if ((PCx - 1 <= NPCx) && (NPCx <= PCx + 1) &&
		(PCy - 1 <= NPCy) && (NPCy <= PCy + 1)) return true;
	return false;
}

Object::Object() {}

Object::~Object() {}
