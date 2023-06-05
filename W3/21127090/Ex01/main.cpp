#include "func.h"

using namespace std;

int main()
{
	// getter and setter
	NhanVien staff;
	staff.setName("Kim");
	cout << "Get name: " << staff.getName() << endl << endl;

	NhanVien staff1;
	// default constructor
	cout << "Default constructor: " << endl;
	staff1.output();

	// Constructor with 5 parameters
	NhanVien staff2("Hoang", 800, "800Hoang", "Truong phong", 2.25);
	cout << "Constructor with 5 parameters: " << endl;
	staff2.output();

	//Constructor with 2 parameters
	NhanVien staff3("Vinh", 500);
	cout << "Constructor with 2 parameters: " << endl;
	staff3.output();

	// Copy constructor
	NhanVien staff4(staff2);
	cout << "Copy constructor: " << endl;
	staff4.output();

	// Destructor
	staff.~NhanVien();
	staff1.~NhanVien();
	staff2.~NhanVien();
	staff3.~NhanVien();
	staff4.~NhanVien();
	
	// Input, Output
	NhanVien staff5;
	cout << "Input: " << endl;
	staff5.input();
	cout << endl << "Output: " << endl;
	staff5.output();
	staff5.~NhanVien();
}