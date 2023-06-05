#include "Shape.h"
#include "Book.h"

int main()
{
	Rectangle rtg;
	rtg.input();
	if (rtg.isRectangle())
	{
		cout << "Toa do hinh chu nhat " << endl;
		rtg.ouput();
		cout << "Chu vi hinh chu nhat: " << rtg.calcPerimeter() << endl;
		cout << "Dien tich hinh chu nhat: " << rtg.calcArea() << endl;
	}
	else cout << "Khong la hinh chu nhat" << endl;
	cout << endl;

	Square sqr;
	sqr.input();
	if (sqr.isSquare())
	{
		cout << "Toa do hinh vuong " << endl;
		sqr.ouput();
		cout << "Chu vi hinh vuong: " << sqr.calcPerimeter() << endl;
		cout << "Dien tich hinh vuong: " << sqr.calcArea() << endl;
	}
	else cout << "Khong la hinh vuong" << endl;

	Library mLib;
	mLib.input();
	cout << endl;
	mLib.output();
	
	string tmp;
	cout << "Input the name of finding book: ";
	getline(cin, tmp);
	mLib.findBookByName(tmp);

	cout << "Input the ID of finding book: ";
	getline(cin, tmp);
	mLib.findBookByID(tmp);

	cout << "Input the category of finding book: ";
	getline(cin, tmp);
	mLib.findBookByCategory(tmp);

}