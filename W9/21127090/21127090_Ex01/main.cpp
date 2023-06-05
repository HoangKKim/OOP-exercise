#include "Staff.h"

vector <Staff*> Staff::listOfSampleObject;

int main()
{
	Staff::addSampleObject(new Lecturer);
	Staff::addSampleObject(new TeachingAssistant);
	Staff::addSampleObject(new Researcher);
	Staff::addSampleObject(new Expert);
	Staff::addSampleObject(new Intern);
	PhongQuanLy managerRoom;
	managerRoom.input();
	managerRoom.output();
	cout << "Enter staff ID is deleted: ";
	string tmp;
	cin >> tmp;
	managerRoom.deleteByID(tmp);
	managerRoom.output();
	managerRoom.~PhongQuanLy(); 
	Staff::deleteSampleObject();
}
