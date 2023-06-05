#include "MangSoNguyen.h"

int main()
{
	//constructor
	MangSoNguyen arr1; 
	int* tmpArr = new int [5] { 1, 2, 3, 4, 5 };
	MangSoNguyen arr2(tmpArr, 5);
	MangSoNguyen arr3(5);
	MangSoNguyen arr4(arr2);
	//destructor
	arr1.~MangSoNguyen();
	arr2.~MangSoNguyen();
	arr3.~MangSoNguyen();
	arr4.~MangSoNguyen();
	delete[]tmpArr;

	MangSoNguyen intArr1, intArr2, resultArr;
	// input - output
	cout << "Nhap mang so nguyen thu nhat" << endl;
	cin >> intArr1;
	cout << endl;
	cout << "Nhap mang so nguyen thu hai" << endl;
	cin >> intArr2;
	cout << endl;

	cout << "Mang so nguyen thu nhat la" << endl;
	cout << intArr1 << endl;

	cout << "Mang so nguyen thu hai la" << endl;
	cout << intArr2 << endl;

	resultArr = intArr1 + intArr2;
	cout << "intArr1 + intArr2: " << endl;
	cout << resultArr << endl;

	resultArr = intArr1++;
	cout << "intArr1++: " << endl;
	cout << resultArr << endl;

	resultArr = ++intArr2;
	cout << "++intArr2: " << endl;
	cout << resultArr << endl;

	// destructor
	resultArr.~MangSoNguyen();
	intArr1.~MangSoNguyen();
	intArr2.~MangSoNguyen();
}