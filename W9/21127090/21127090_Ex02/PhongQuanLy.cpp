#include "Staff.h"

void PhongQuanLy::input()
{
	int n, i = 0;
	bool flag = true;
	string tmp;
	do
	{
		cout << "Enter kind of staff to add to list: ";
		cin >> tmp;
		cin.ignore();
		Staff* tmpStaff = Staff::createObjectByName(tmp);
		if (tmpStaff != NULL)
		{
			tmpStaff->input();
			listOfStaff.push_back(tmpStaff);
		}
		cout << "Continue (yes or no): ";
		cin >> tmp;
		if (tmp == "yes")
		{
			flag = true;
		}
		else flag = false;
		cout << endl;
	} while (flag == true);
}

void PhongQuanLy::output()
{
	if (listOfStaff.size() == 0)
	{
		return;
	}
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		cout << listOfStaff[i]->getNameClass();
		cout << endl;
		listOfStaff[i]->output();
		cout << endl;
	}
}

void PhongQuanLy::deleteByID(string mID)
{
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		if (listOfStaff[i]->getID() == mID)
		{
			listOfStaff.erase(listOfStaff.begin() + i);
			cout << "Delete successfully" << endl;
			return;
		}
	}
	cout << "Don't have data about this ID" << endl;
}

float PhongQuanLy::calcSalary()
{
	float tmp = 0;
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		listOfStaff[i]->setSalary();
		tmp = tmp + listOfStaff[i]->getSalary();
	}
	return tmp;
}

void PhongQuanLy::highestSalary()
{
	if (listOfStaff.size() == 0)
	{
		return;
	}
	int max = 0, pos = 0;
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		if (listOfStaff[i]->getSalary() > max)
		{
			max = listOfStaff[i]->getSalary();
			pos = i;
		}
	}
	cout << "Staff has hightest salary: " << endl;
	listOfStaff[pos]->getNameClass();
	cout << endl;
	listOfStaff[pos]->output();
}
PhongQuanLy::~PhongQuanLy()
{
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		listOfStaff[i]->~Staff();
		delete listOfStaff[i];
		listOfStaff[i] = nullptr;
	}
	listOfStaff.clear();
}