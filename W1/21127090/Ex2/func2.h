#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Point
{
private:
	float x, y;

public:
	void input();
	void output();
	float calDistance(Point A, Point B);
};