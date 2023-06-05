#include "func2.h"

using namespace std;

int main()
{
	Point A, B, tmp;
	float distance;
	cout << "Input point A: " << endl;
	A.input();
	cout << "Input point B: " << endl;
	B.input();

	cout << endl;
	cout << "Output is: " << endl;
	cout << "Point A: ";
	A.output();
	cout << "Point B: ";
	B.output();
	cout << endl;

	distance = tmp.calDistance(A,B);
	cout << "Distance from A to B is: " << distance << endl;

}