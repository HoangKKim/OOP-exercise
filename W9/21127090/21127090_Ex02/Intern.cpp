#include "Staff.h"

Intern::Intern() :Staff()
{
	projectCode.resize(0);
	timeOfIntern = 0;
}
Intern::Intern(string name, string birthday, string masoNS, int init_tgThucTap, vector <string> duan) :
	Staff(name, birthday, masoNS)
{
	timeOfIntern = init_tgThucTap;
	projectCode.resize(duan.size());
	for (int i = 0; i < projectCode.size(); i++)
	{
		projectCode[i] = duan[i];
	}
}
string Intern::getNameClass()
{
	return "Intern";
}

void Intern::setSalary()
{
	int count = 0;
	for (int i = 0; i < projectCode.size(); i++)
	{
		if (projectCode[i].at(0) == 'R')
		{
			count++;
		}
	}
	this->salary = 0.1 * count * 10000;
}

void Intern::input()
{
	Staff::input();
	int n;
	cout << "- Time of intern: ";
	cin >> timeOfIntern;
	cout << "- Number of projects joining: ";
	cin >> n;
	projectCode.resize(n);
	cout << "- List of project code " << endl;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "+ Project " << i + 1 << ": ";
		getline(cin, projectCode[i]);
	}
}

void Intern::output()
{
	Staff::output();
	cout << "- Time of intern: " << timeOfIntern << endl;
	cout << "- Number of projects joining: " << projectCode.size() << endl;
	cout << "- List of project code " << endl;
	for (int i = 0; i < projectCode.size(); i++)
	{
		cout << "+ Project " << i + 1 << ": " << projectCode[i] << endl;
	}
}

Intern::~Intern()
{
	timeOfIntern = 0;
	for (int i = 0; i < projectCode.size(); i++)
	{
		projectCode[i].clear();
	}
	projectCode.clear();
}

Staff* Intern::Clone()
{
	return new Intern(*this);
}