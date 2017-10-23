#include "Coord.h"

Coord::Coord() {
	this->x = 0;
	this->y = 0;
}


Coord::Coord(int x, int y){
	this->x = x;
	this->y = y;
}


Coord::~Coord(){
}

int Coord::getX(){
	return this->x;
}

int Coord::getY(){
	return this->y;
}

void Coord::setXY(int x, int y){
	this->x = x;
	this->y = y;
}
