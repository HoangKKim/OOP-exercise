#include "CoVua.h"

int main()
{
	// default constructor
	Diem point1;
	// parameted constructor
	Diem point2(1, 1);
	 //overload >>, <<
	Diem point3;
	cin >> point3;
	cout << point3;
	// overload =
	point1 = point2;
	cout << point1;
	// destructor
	point1.~Diem();
	point2.~Diem();
	point3.~Diem();

	QuanCo quanco1;
	quanco1.input();
	quanco1.output();



}