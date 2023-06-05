#include "PhanSo.h"

int main()
{
	// constructor 
	PhanSo psa; // default
	PhanSo psb(1, 2);// parameted
	PhanSo psc(psa); // copy
	// destructor
	psa.~PhanSo();
	psb.~PhanSo();
	psc.~PhanSo();
	
	// input
	PhanSo ps1, ps2, result;
	cout << "Nhap phan so duoi dang a/b" << endl;
	cout << "Nhap phan so thu nhat: ";
	cin >> ps1;
	cout << "Nhap phan so thu hai: ";
	cin >> ps2;

	// overload operator
	cout << ps1<<" + "<<ps2<<" : ";
	result = ps1 + ps2;
	cout << result;
	cout << endl;

	cout << ps1 << " - " << ps2 << " : ";
	result = ps1 - ps2;
	cout << result;
	cout << endl;

	cout << ps1 << " * " << ps2 << " : ";
	result = ps1 * ps2;
	cout << result;
	cout << endl;

	cout << ps1 << " / " << ps2 << " : ";
	result = ps1 / ps2;
	cout << result;
	cout << endl;

	cout << endl;
	cout << ps1<<" += "<<ps2<<" : ";
	ps1 += ps2;
	cout << ps1;
	cout << endl;

	cout << ps1 << " -= " << ps2 << ": ";
	ps1 -= ps2;
	cout << ps1;
	cout << endl;

	cout << ps1 << " *= " << ps2 << ": ";
	ps1 *= ps2;
	cout << ps1;
	cout << endl;

	cout << ps1 << " /= " << ps2 << ": ";
	ps1 /= ps2;
	cout << ps1;
	cout << endl << endl;

	cout << "Phan so 1: " << ps1 << endl;
	cout << "Phan so 2: " << ps2 << endl;
	bool test;
	cout << ps1 << " == " << ps2 << " : ";
	test = ps1 == ps2;
	if (test == 0)
	{
		cout << "false";
	}
	else cout << "true";
	cout << endl;

	cout << ps1 << " > " << ps2 << " : ";
	test = ps1 > ps2;
	if (test == 0)
	{
		cout << "false";
	}
	else cout << "true";
	cout << endl;

	cout << ps1 << " < " << ps2 << " : ";
	test = ps1 < ps2;
	if (test == 0)
	{
		cout << "false";
	}
	else cout << "true";
	cout << endl;

	cout << ps1 << " >= " << ps2 << " : ";
	test = ps1 >= ps2;
	if (test == 0)
	{
		cout << "false";
	}
	else cout << "true";
	cout << endl;

	cout << ps1 << " <= " << ps2 << " : ";
	test = ps1 <= ps2;
	if (test == 0)
	{
		cout << "false";
	}
	else cout << "true";
	cout << endl;

	cout << "!=";
	test = ps1 != ps2;
	if (test == 0)
	{
		cout << "false";
	}
	else cout << "true";
	cout << endl << endl;

	PhanSo res2;
	cout << "result = " << ps1 << " ++: ";
	res2=ps1++;
	cout << res2 << endl;

	cout << "result = " << "++ " << ps1 << ": ";
	res2=++ps1;
	cout << res2 << endl;

	cout << "result = " << ps1 << " --: ";
	res2=ps1--;
	cout << res2 << endl;

	cout << "result = " << "-- " << ps1<<": ";
	res2=--ps1;
	cout << res2 << endl;

	ps1.~PhanSo();
	ps2.~PhanSo();
	res2.~PhanSo();
	result.~PhanSo();
}