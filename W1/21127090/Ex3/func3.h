#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Point
{
private:
	float x, y;
public:
	void input();
	void output();
	float calDistance(Point A, Point B);
	Point calVector(Point A, Point B);
	bool isPerpendicular(Point A, Point B, Point C, Point D);
	bool isParallel(Point A, Point B, Point C, Point D);
	bool isEqual(Point A, Point B, Point C, Point D);

};

class Rectangle
{
private:
	Point A, B, C, D;
public:
	void input();
	void output();
	bool isRectangle(Rectangle rtg);
	float calPerimeter(Rectangle rtg);
	float calArea(Rectangle rtg);
};
