#pragma once
#ifndef COORD_H
#define COORD_H
class Coord
{
private:
	int x, y;
public:
	Coord();
	Coord(int x, int y);
	~Coord();
	int getX();
	int getY();
	void setXY(int x, int y);

};
#endif

