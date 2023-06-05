#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class NhanVien
{
private: 
	string name;
	int workingDays;
	string id;
	string pos;
	float coeffiPay;
public:
	// getter
	string getName();
	int getWorkingDays();
	string getID();
	string getPos();
	float getcoeffiPay();
	// setter
	void setName(string);
	void setWorkingDays(int);
	void setID(string);
	void setPos(string);
	void setcoeffiPay(float);
	// constructor
	NhanVien(); // default constructor
	// parameter constructor
	NhanVien(string name, int workingDays, string id, string pos, float coeffiPay);
	NhanVien(string name, int workingDays);
	NhanVien(const NhanVien& nhanvien);
	// desconstructor
	~NhanVien();
	// input
	void input();
	void output();
};
