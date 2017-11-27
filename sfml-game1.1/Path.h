#pragma once
#ifndef PATH_H
#define PATH_H
class PathSeg;
class Path{
private:
	PathSeg* pathArr;
public:
	Path();
	~Path();
};
#endif
