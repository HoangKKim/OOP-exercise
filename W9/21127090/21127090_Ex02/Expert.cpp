#include "Staff.h"

Expert::Expert() :Staff()
{
	exp = 0;
	projectCode.resize(0);
}

Expert::Expert(string name, string birthday, string masoNS, vector <string> maDA, int sonamKN) :
	Staff(name, birthday, masoNS)
{
	exp = sonamKN;
	projectCode.resize(maDA.size());
	for (int i = 0; i < projectCode.size(); i++)
	{
		projectCode[i] = maDA[i];
	}
}

string Expert::getNameClass()
{
	return "Expert";
}

void Expert::input()
{
	int n;
	Staff::input();
	cout << "- Experience: ";
	cin >> exp;
	cout << "- Number of project done: ";
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

void Expert::setSalary()
{
	int count = 0;
	for (int i = 0; i < projectCode.size(); i++)
	{
		if (projectCode[i].at(0) == 'T')
		{
			count++;
		}
	}
	this->salary = (exp * 4 + count) * 18000;
}

void Expert::output()
{
	Staff::output();
	cout << "- Experience: " << exp << endl;
	cout << "- Number of project done: " << projectCode.size() << endl;
	cout << "- List of project code " << endl;
	for (int i = 0; i < projectCode.size(); i++)
	{
		cout << "+ Project " << i + 1 << ": " << projectCode[i] << endl;
	}
}

Expert::~Expert()
{
	Staff::~Staff();
	exp = 0;
	projectCode.clear();
	projectCode.resize(0);
}

Staff* Expert::Clone()
{
	return new Expert(*this);
}
