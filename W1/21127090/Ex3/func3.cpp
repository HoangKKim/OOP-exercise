#include "func3.h"

void Point::input()
{
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
}

void Point::output()
{
	cout << "(" << x << ";" << y << ")" << endl;
}

float Point::calDistance(Point A, Point B)
{
	float result;
	result = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
	return result;
}

Point Point::calVector(Point A, Point B)
{
	Point tmp;
	tmp.x = B.x - A.x;
	tmp.y = B.y - A.y;
	return tmp;
}

// check vuong goc
bool Point::isPerpendicular(Point A, Point B, Point C, Point D)
{
	Point AB, AD;
	AB = A.calVector(A, B);
	AD = A.calVector(A, D);
	if (AB.x * AD.x + AB.y * AD.y == 0)
	{
		return true;
	}
	return false;
}

// check song song
bool Point::isParallel(Point A, Point B, Point C, Point D)
{
	if (A.x == D.x && B.x == C.x && A.y == B.y && C.y == D.y)
	{
		return true;
	}
	return false;
}

// check canh bang
bool Point::isEqual(Point A, Point B, Point C, Point D)
{
	float AB, DC;
	Point tmp;
	AB = tmp.calDistance(A, B);
	DC = tmp.calDistance(D, C);
	if (AB == DC)
	{
		return true;
	}
	return false;

}

void Rectangle::input()
{
	cout << "Input point A:" << endl;
	A.input();
	cout << "Input point B:" << endl;
	B.input();
	cout << "Input point C:" << endl;
	C.input();
	cout << "Input point D:" << endl;
	D.input();
}

void Rectangle::output()
{
	cout << "Rectangle with 4 points: " << endl;
	cout << "A";
	A.output();
	cout << "B";
	B.output();
	cout << "C";
	C.output();
	cout << "D";
	D.output();
}

bool Rectangle::isRectangle(Rectangle rtg)
{
	Point tmp;
	bool checkParallel = tmp.isParallel(rtg.A, rtg.B, rtg.C, rtg.D);
	bool checkEqual = tmp.isEqual(rtg.A,rtg.B,rtg.C,rtg.D);
	bool checkPerpendicular = tmp.isPerpendicular(rtg.A, rtg.B, rtg.C, rtg.D);
	if (checkParallel && checkEqual && checkPerpendicular)
	{
		return true;
	}
	return false;
	
}

float Rectangle::calPerimeter(Rectangle rtg)
{
	float AB, AD;
	Point tmp;
	AB = tmp.calDistance(rtg.A, rtg.B);
	AD = tmp.calDistance(rtg.A, rtg.D);
	return (AB + AD) * 2;
}

float Rectangle::calArea(Rectangle rtg)
{
	float AB, AD;
	Point tmp;
	AB = tmp.calDistance(rtg.A, rtg.B);
	AD = tmp.calDistance(rtg.A, rtg.D);
	return (AB * AD);
}
