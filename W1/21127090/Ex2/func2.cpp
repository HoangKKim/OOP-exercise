#include "func2.h"

void Point::input()
{
	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
}

void Point::output()
{
	cout << "(" << x << ";" << y << ")" << endl;
}

float Point::calDistance(Point A, Point B)
{
	float result;
	result = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	return result;
}