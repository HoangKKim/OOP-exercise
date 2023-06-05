#pragma once
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Point
{
protected:
	int x;
	int y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int m_x, int m_y);
	~Point()
	{
		x = 0;
		y = 0;
	}
	void setPoint(int m_x, int m_y);
	int getX();
	int getY();
	float calcDistance(Point A, Point B);
	Point calcVector(Point A, Point B);
};

class Rectangle 
{
protected:
	Point A, B, C, D;
public:
	Rectangle()
	{
		A.setPoint(0, 1);
		B.setPoint(2, 1);
		C.setPoint(2, 0);
		D.setPoint(0, 0);
	}
	Rectangle(Point mA, Point mB, Point mC, Point mD);
	~Rectangle()
	{
		A.setPoint(0, 1);
		B.setPoint(2, 1);
		C.setPoint(2, 0);
		D.setPoint(0, 0);
	}
	void setRectangle(Point mA, Point mB, Point mC, Point mD);
	bool isPerpendicular();
	bool isParallel();
	bool isEqual();
	bool isRectangle();
	float calcPerimeter();
	float calcArea();
	void input();
	void ouput();
};

class Square :public Rectangle
{
public:
	Square()
	{
		A.setPoint(0, 2);
		B.setPoint(2, 2);
		C.setPoint(2, 0);
		D.setPoint(0, 0);
	}
	Square(Point mA, Point mB, Point mC, Point mD);
	bool isSquare();
};

