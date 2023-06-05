#include "func1.h"

Student::Student()
{
	name = phoneNum = '\0';
	score = 0;
}

bool Student::checkName()
{
	if (name.length() > 20)
	{
		return false;
	}
	
	for (int i = 0; i < name.length(); i++)
	{
		if ((name[i] < 'A' || name[i]>'Z') && (name[i] < 'a' || name[i]>'z') && (name[i] != ' '))
		{
			return false;	
		}
	}
	
	return true;
}

bool Student::checkPhoneNum()
{
	if (phoneNum.length() > 11)
	{
		return false;
	}

	for (int i = 0; i < phoneNum.length(); i++)
	{
		if (phoneNum[i] < '0' || phoneNum[i]>'9')
		{
			return false;
		}
	}
	return true;
}

bool Student::checkScore()
{
	if (score < 0 || score > 10)
	{
		return false;
	}
	return true;
}

void Student::input()
{
	Student tmp;
	do
	{
		cout << "Name: ";
		getline(cin, tmp.name);
		cout << "Phone number: ";
		getline(cin, tmp.phoneNum);
		cout << "Avarage score: ";
		cin >> tmp.score;
		cout << endl;
		cin.ignore();
	} while (!tmp.checkName() || !tmp.checkPhoneNum() || !tmp.checkScore());
	name = tmp.name;
	phoneNum = tmp.phoneNum;
	score = tmp.score;
}

void Student::output()
{
	cout << "Name: " << this->name << endl;
	cout << "Phone number: " << this->phoneNum << endl;
	cout << "Avarage score: " << this->score << endl;
}