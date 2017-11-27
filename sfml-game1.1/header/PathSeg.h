#ifndef PATHSEG_H
#define PATHSEG_H
#include "SFML\Graphics.hpp" 
class PathSeg{
private:
	sf::Vector2f start, finish;
	bool isFirst;
	bool isLast;
	PathSeg* nextSeg;
	PathSeg* lastSeg;

public:
	PathSeg();
	~PathSeg();
};
#endif

