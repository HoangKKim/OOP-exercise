#pragma once
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Diem
{
private:
	int x;
	int y;
public:
	Diem();
	Diem(int, int);
	friend istream& operator>>(istream& is, Diem& point);
	friend ostream& operator<<(ostream& os, const Diem& point);
	Diem operator=(const Diem& point);
	~Diem();
	void setQuanCo(int m_x, int m_y);
	int getX();
	int getY();
};

class QuanCo
{
private:
	string tenQuanCo;
	vector <Diem> duongdi;
	Diem vitri_hientai;
public:
	QuanCo();
	QuanCo(string, vector <Diem>, Diem);
	QuanCo(const QuanCo& );
	void input();
	void output();
	bool PhongCap(vector <QuanCo> QC_doiphuong);	
};

float minPath(Diem, Diem);