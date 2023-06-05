#include "func3.h"

using namespace std;

int main()
{
	Rectangle rtg;
	cout << "Input points of rectangle ABCD: " << endl;
	rtg.input();
	cout << endl;
	rtg.output();
	bool check = rtg.isRectangle(rtg);
	if (check == 1)
	{
		cout << "This is a rectangle!" << endl;

		float P = rtg.calPerimeter(rtg);
		float S = rtg.calArea(rtg);

		cout << "Perimeter: " << setprecision(2) << fixed << P << endl;
		cout << "Area: " << setprecision(2) << fixed << S << endl;

	}
	else cout << "This is not a rectangle!" << endl;
	
	
}