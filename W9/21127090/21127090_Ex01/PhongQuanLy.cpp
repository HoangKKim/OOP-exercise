#include "Staff.h"
PhongQuanLy::PhongQuanLy()
{
	listOfStaff.resize(0);
}

PhongQuanLy::PhongQuanLy(vector <Staff*>m_listOfStaff)
{
	listOfStaff.resize(m_listOfStaff.size());
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		listOfStaff[i] = m_listOfStaff[i];
	}
}

PhongQuanLy::PhongQuanLy(const PhongQuanLy& mPhongQuanLy)
{
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		delete listOfStaff[i];
	}
	listOfStaff.clear();

	listOfStaff.resize(mPhongQuanLy.listOfStaff.size());
	for (int i = 0; i < listOfStaff.size(); i++)
	{
		listOfStaff[i] = mPhongQuanLy.listOfStaff[i];
	}
}

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
		cout<<listOfStaff[i]->getNameClass();
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