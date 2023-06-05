#include "Staff.h"

Researcher::Researcher() : Staff()
{
	exp = 0;
	projectCode.resize(0);
}
Researcher::Researcher(string name, string birthday, string masoNS, vector <string> maDA, int sonamKN) :
	Staff(name, birthday, masoNS)
{
	exp = sonamKN;
	projectCode.resize(maDA.size());
	for (int i = 0; i < projectCode.size(); i++)
	{
		projectCode[i] = maDA[i];
	}
}
string Researcher::getNameClass()
{
	return "Researcher";
}

void Researcher::input()
{
	int n;
	Staff::input();
	cout << "- Experience: ";
	cin >> exp;
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

void Researcher::setSalary()
{
	int count = 0;
	for (int i = 0; i < projectCode.size(); i++)
	{
		if (projectCode[i].at(0) == 'D')
		{
			count++;
		}
	}
	this->salary = (exp * 2 + count) * 20000;
}

void Researcher::output()
{
	Staff::output();
	cout << "- Experience: " << exp << endl;
	cout << "- Number of projects joining: " << projectCode.size() << endl;
	cout << "- List of project code " << endl;
	for (int i = 0; i < projectCode.size(); i++)
	{
		cout << "+ Project " << i + 1 << ": " << projectCode[i] << endl;
	}
}

Researcher::~Researcher()
{
	Staff::~Staff();
	exp = 0;
	projectCode.clear();
	projectCode.resize(0);
}

Staff* Researcher::Clone()
{
	return new Researcher(*this);
}