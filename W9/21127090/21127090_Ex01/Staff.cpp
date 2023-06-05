#include "Staff.h"

Staff::Staff()
{
	name = '\0';
	birthday = '\0';
	id = '\0';
	salary = 0;
}

Staff::Staff(string name, string birthday, string masoNS)
{
	name = name;
	birthday = birthday;
	id = masoNS;
}

Staff::~Staff()
{
	name.clear();
	birthday.clear();
	id.clear();
	salary = 0;
}

void Staff::input()
{
	cout << "- Full name: ";
	getline(cin, name);
	cout << "- Date of birth: ";
	getline(cin, birthday);
	cout << "- Staff ID: ";
	getline(cin, id);
}

void Staff::output()
{
	cout << "- Full name: " << name << endl;
	cout << "- Date of birth: " << birthday << endl;
	cout << "- Staff id: " << id << endl;
}

float Staff::getSalary()
{
	return this->salary;
}

void Staff::addSampleObject(Staff *nStaff)
{
	if (nStaff == NULL)
	{
		return;
	}
	int pos = -1;
	for (int i = 0; i < listOfSampleObject.size(); i++)
	{
		Staff* sample = listOfSampleObject[i];
		if (nStaff->getNameClass() == sample->getNameClass())
		{
			pos = i;
		}
	}
	if (pos == -1)
	{
		listOfSampleObject.push_back(nStaff);
	}
}

Staff* Staff::createObjectByName(string nName)
{
	for (int i = 0; i < listOfSampleObject.size(); i++)
	{
		Staff* sample = listOfSampleObject[i];
		if (sample->getNameClass() == nName)
		{
			return listOfSampleObject[i]->Clone();
		}
	}
	cout << "Name of object is invalid" << endl;
	return NULL;
}

void Staff::deleteSampleObject()
{
	for (int i = 0; i < listOfSampleObject.size(); i++)
	{
		delete listOfSampleObject[i];
		listOfSampleObject[i] = NULL;
	}
}

string Staff::getID()
{
	return id;
}