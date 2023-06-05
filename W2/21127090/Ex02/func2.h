#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student
{
private:
	string name;
	string phoneNum;
	float score;
public:
	Student();
	string getName();
	bool checkName();
	bool checkPhoneNum();
	bool checkScore();
	float getScore();
	void output();
	void inputTextFile(fstream& fi);
	void inputConsole();
};

class Class
{
private:
	vector <Student> arrStudent;
public: 
	void addStudent(Student newStudent);
	void deleteStudent(string deletedStudent);
	void descendingOrder();
	int partition(int low, int high);
	void quickSort(int low, int high);
	void output();
	void input(const char* filePath);
};
