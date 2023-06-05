#include "func2.h"

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
		if ((name[i] < 'A' || name[i]>'Z') && (name[i] < 'a' || name[i]>'z'))
		{
			if (name[i] != ' ')
			{
				return false;
			}
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

void Student::output()
{
	cout << "Name: " << this->name << endl;
	cout << "Phone number: " << this->phoneNum << endl;
	cout << "Avarage score: " << this->score << endl;
}

void Student::inputTextFile(fstream &fi)
{
	getline(fi, name);
	getline(fi, phoneNum);
	fi >> score;
}

void Student::inputConsole()
{
	bool flag = true;
	do
	{
		if (flag == false)
		{
			cout << "Khong hop le, xin nhap lai!" << endl;
			cin.ignore();
		}
		cout << "Name: ";
		getline(cin, name);
		//cin.ignore();
		cout << "Phone number: ";
		cin.ignore();
		getline(cin, phoneNum);
		cout << "Average score: ";
		cin >> score;
		flag = false;
	} while (!this->checkName() || !this->checkPhoneNum() || !this->checkScore());
}
