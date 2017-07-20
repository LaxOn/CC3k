#ifndef OBJECT_H
#define OBJECT_H
#include "object.h"
#include "info.h"

void Object::setCoords(int x, int y) {
		this->x = x;
		this->y = y;	
}

void Object::setDisp(char charDisp) {
	this->charDisp = charDisp;	
}

void Object::setTile(Tile *t) {
											// change x and y from y
	address = t;
}

Info Object::getInfo();
	// call constructor for Info
	return Object{x,y};
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

#endif
i