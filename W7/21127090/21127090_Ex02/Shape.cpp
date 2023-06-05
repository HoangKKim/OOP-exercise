#include "Shape.h"

// Point
Point::Point(int m_x, int m_y)
{
	x = m_x;
	y = m_y;
}

void Point::setPoint(int m_x, int m_y)
{
	x = m_x; 
	y = m_y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

float Point::calcDistance(Point A, Point B)
{
	float dis;
	dis = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	return dis;
}

Point Point::calcVector(Point A, Point B)
{
	Point tmp;
	tmp.x = B.x - A.x;
	tmp.y = B.y - A.y;
	return tmp;
}

// -------------------------------------------------------------------------- // 

// Rectangle
Rectangle::Rectangle(Point mA, Point mB, Point mC, Point mD)
{
	A = mA;
	B = mB;
	C = mC;
	D = mD;
}

void Rectangle::setRectangle(Point mA, Point mB, Point mC, Point mD)
{
	A = mA;
	B = mB;
	C = mC;
	D = mD;
}

// check vuong goc
bool Rectangle::isPerpendicular()
{
	Point AB, AD;
	AB = A.calcVector(A, B);
	AD = A.calcVector(A, D);
	if (AB.getX() * AD.getX() + AB.getY() * AD.getY() == 0)
	{
		return true;
	}
	return false;
}

// check song song
bool Rectangle::isParallel()
{
	if (A.getX() == D.getX() && B.getX() == C.getX() && A.getY() == B.getY() && C.getY() == D.getY())
	{
		return true;
	}
	return false;
}

// check canh bang
bool Rectangle::isEqual()
{
	float AB, DC;
	Point tmp;
	AB = tmp.calcDistance(A, B);
	DC = tmp.calcDistance(D, C);
	if (AB == DC)
	{
		return true;
	}
	return false;

}

bool Rectangle::isRectangle()
{
	bool checkParallel = this->isParallel();
	bool checkEqual = this->isEqual();
	bool checkPerpendicular = this->isPerpendicular();
	if (checkParallel && checkEqual && checkPerpendicular)
	{
		return true;
	}
	return false;
}

float Rectangle::calcPerimeter()
{
	float AB, AD;
	AB = A.calcDistance(A, B);
	AD = A.calcDistance(A, D);
	return (AB + AD) * 2;
}

float Rectangle::calcArea()
{
	float AB, AD;
	AB = A.calcDistance(A, B);
	AD = A.calcDistance(A, D);
	return AB * AD;
}

void Rectangle::input()
{
	int x, y;
	cout << "Toa do A: ";
	cin >> x >> y;
	A.setPoint(x, y);
	
	cout << "Toa do B: ";
	cin >> x >> y;
	B.setPoint(x, y);
	
	cout << "Toa do C: ";
	cin >> x >> y;
	C.setPoint(x, y);

	cout << "Toa do D: ";
	cin >> x >> y;
	D.setPoint(x, y);
}

void Rectangle::ouput()
{
	cout << "Toa do A(" << A.getX() << ";" << A.getY() << ")" << endl;
	cout << "Toa do B(" << B.getX() << ";" << B.getY() << ")" << endl;
	cout << "Toa do C(" << C.getX() << ";" << C.getY() << ")" << endl;
	cout << "Toa do D(" << D.getX() << ";" << D.getY() << ")" << endl;
}

// -------------------------------------------------------------------------- // 
// Square
Square::Square(Point mA, Point mB, Point mC, Point mD)
{
	A = mA;
	B = mB;
	C = mC;
	D = mD;
}

bool Square::isSquare()
{
	if (this->isRectangle() == true)
	{
		if (A.calcDistance(A, B) == A.calcDistance(A, D))
		{
			return true;
		}
	}
	return false;
}