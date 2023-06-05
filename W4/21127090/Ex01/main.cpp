#include "func1.h"

int main()
{
	PhanSo ps1, ps2, rs;
	cout << "Nhap phan so duoi dang a/b" << endl;
	cout << "Phan so 1: " ;
	cin >> ps1;
	cout << "Phan so 2: " ;
	cin >> ps2;

	cout << "Addition: ";
	rs = ps1 + ps2;
	rs.output1();
	rs.output2();

	cout << "Subtraction: ";
	rs = ps1 - ps2;
	rs.output1();
	rs.output2();
	

	cout << "Multiplication: ";
	rs = ps1 * ps2;
	rs.output1();
	rs.output2();

	cout << "Division: ";
	rs = ps1 / ps2;
	rs.output1();
	rs.output2();
	
	ps1.~PhanSo();
	ps2.~PhanSo();
	rs.~PhanSo();

}