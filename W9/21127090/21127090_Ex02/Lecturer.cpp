#include "Staff.h"

Lecturer::Lecturer(string name, string birthday, string masoNS, string hham, string hvi, int sonamgd, vector <string> ds) :
	Staff(name, birthday, masoNS)
{
	academicRank = hham;
	degree = hvi;
	exp = sonamgd;
	listOfSubject.resize(ds.size());
	for (int i = 0; i < ds.size(); i++)
	{
		listOfSubject[i] = ds[i];
	}
}

Lecturer::Lecturer() {}

string Lecturer::getNameClass()
{
	return "Lecturer";
}

Staff* Lecturer::Clone()
{
	return new Lecturer(*this);
}

void Lecturer::input()
{
	Staff::input();
	int n;
	cout << "- Academic rank: ";
	getline(cin, academicRank);
	cout << "- Degree: ";
	getline(cin, degree);
	cout << "- Experience: ";
	cin >> exp;
	cout << "- Number of teaching subjects: ";
	cin >> n;
	listOfSubject.resize(n);
	cout << "- List of teaching subjects: " << endl;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "+ Subject " << i + 1 << ": ";
		getline(cin, listOfSubject[i]);
	}
}

void Lecturer::setSalary()
{
	this->salary = (listOfSubject.size() * exp * 0.12) * 20000;
}

void Lecturer::output()
{
	Staff::output();
	cout << "- Academic rank: " << academicRank << endl;
	cout << "- Degree: " << degree << endl;
	cout << "- Experience: " << exp << endl;
	cout << "- Number of teaching subjects: " << listOfSubject.size() << endl;
	cout << "- List of teaching subjects: " << endl;
	for (auto i = 0; i < listOfSubject.size(); i++)
	{
		cout << "+ Subject " << i + 1 << ": " << listOfSubject[i] << endl;
	}
}

Lecturer::~Lecturer()
{
	Staff::~Staff();
	academicRank.clear();
	degree.clear();
	exp = 0;
	listOfSubject.clear();
	listOfSubject.resize(0);
}
