#include "Staff.h"

TeachingAssistant::TeachingAssistant() : Staff()
{
	numberOfTCSubject = 0;
}

TeachingAssistant::TeachingAssistant(string name, string birthday, string masoNS, int somonTG) :
	Staff(name, birthday, masoNS)
{
	numberOfTCSubject = somonTG;
}

TeachingAssistant::~TeachingAssistant()
{
	Staff::~Staff();
	numberOfTCSubject = 0;
}

void TeachingAssistant::input()
{
	Staff::input();
	cout << "- Number of teaching assistant subjects: ";
	cin >> numberOfTCSubject;
}

string TeachingAssistant::getNameClass()
{
	return "TeachingAssistant";
}

void TeachingAssistant::setSalary()
{
	this->salary = (numberOfTCSubject * 0.3) * 18000;
}

void TeachingAssistant::output()
{
	Staff::output();
	cout << "- Number of teaching assistant subjects: " << numberOfTCSubject << endl;
}

Staff* TeachingAssistant::Clone()
{
	return new TeachingAssistant(*this);
}
