#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	string phoneNum;
	float score;
public:
	Student();
	bool checkName();
	bool checkPhoneNum();
	bool checkScore();
	void input();
	void output();
};
