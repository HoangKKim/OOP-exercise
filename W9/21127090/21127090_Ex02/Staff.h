#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Staff
{
protected:
	string name;
	string birthday;
	string id;
	float salary;
	static vector <Staff*> listOfSampleObject;
public:
	Staff();
	Staff(string name, string birthday, string masoNS);
	virtual void input();
	virtual void output();
	virtual void setSalary() = 0;
	float getSalary();
	string getID();
	virtual ~Staff();

	virtual Staff* Clone() = 0;
	virtual string getNameClass() = 0;
	static void addSampleObject(Staff* nStaff);
	static Staff* createObjectByName(string nName);
	static void deleteSampleObject();
};

class Lecturer :public Staff
{
private:
	string  academicRank;
	string degree;
	int exp;
	vector <string> listOfSubject;
public:
	Lecturer();
	Lecturer(string name, string birthday, string masoNS, string hham, string hvi, int sonamgd, vector <string> ds);
	void setSalary();
	void input();
	void output();
	string getNameClass();
	Staff* Clone();
	~Lecturer();
};

class TeachingAssistant :public Staff
{
private:
	int numberOfTCSubject;
public:
	TeachingAssistant();
	TeachingAssistant(string name, string birthday, string masoNS, int somonTG);
	void setSalary();
	void input();
	void output();
	string getNameClass();
	Staff* Clone();
	~TeachingAssistant();
};

class Researcher :public Staff
{
private:
	vector <string> projectCode;
	int exp;
public:
	Researcher();
	Researcher(string name, string birthday, string masoNS, vector <string> maDA, int sonamKN);
	void setSalary();
	void input();
	void output();
	string getNameClass();
	Staff* Clone();
	~Researcher();
};

class Expert :public Staff
{
private:
	vector <string> projectCode;
	int exp;
public:
	Expert();
	Expert(string name, string birthday, string masoNS, vector <string> maDA, int sonamKN);
	void setSalary();
	void input();
	void output();
	string getNameClass();
	Staff* Clone();
	~Expert();
};

class Intern : public Staff
{
private:
	int timeOfIntern;
	vector<string> projectCode;
public:
	Intern();
	Intern(string name, string birthday, string masoNS, int init_tgThucTap, vector <string> duan);
	void setSalary();
	void input();
	void output();
	string getNameClass();
	Staff* Clone();
	~Intern();

};

class PhongQuanLy
{
private:
	vector<Staff*> listOfStaff;
	static PhongQuanLy* instance;
	PhongQuanLy() {}
public:
	static PhongQuanLy* getInstance()
	{
		if (instance == NULL)
		{
			return new PhongQuanLy();
		}
		return instance;
	}
	void input();
	void output();
	float calcSalary();
	void highestSalary();
	void deleteByID(string mID);
	static void deleteInstance()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
	~PhongQuanLy();
};
