#include "func2.h"

int main()
{
	Class arrStudent;
	//read data from file txt
	arrStudent.input("LopHoc.txt");

	Student newStudent;
	// add a student 
	cout << "Nhap thong tin hoc sinh can them: " << endl;
	newStudent.inputConsole();
	arrStudent.addStudent(newStudent);
	cout << endl;

	cout << "Danh sach hoc sinh sau khi them: " << endl;
	arrStudent.output();
	cout << endl;

	string deletedStudent;
	cout << "Nhap ten hoc sinh can xoa: ";
	cin.ignore();
	getline(cin, deletedStudent);
	arrStudent.deleteStudent(deletedStudent);

	cout << "Danh sach hoc sinh sau khi xoa: " << endl;
	arrStudent.output();
	cout << endl;

	arrStudent.descendingOrder();
	cout << "Danh sach hoc sinh sau khi sap xep: " << endl;
	arrStudent.output();
	cout << endl;
	
}