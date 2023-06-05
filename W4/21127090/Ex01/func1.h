#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class PhanSo
{
private:
	int* tuso;
	int* mauso;
public:
	PhanSo();
	PhanSo(int);
	PhanSo(int, int);
	PhanSo(const PhanSo& ps);
	~PhanSo();
	int getNumerator();
	int getDenominator();
	void setNumerator(int);
	void setDenominator(int);
	PhanSo& operator=(const PhanSo& a);
	friend PhanSo operator+(const PhanSo& a, const PhanSo& b);
	friend PhanSo operator-(const PhanSo& a, const PhanSo& b);
	friend PhanSo operator*(const PhanSo& a, const PhanSo& b);
	friend PhanSo operator/(const PhanSo& a, const PhanSo& b);
	

	void output1();
	void output2();

	void reduce();
	friend istream& operator>>(istream& fi,const PhanSo& ps);
	friend ostream& operator<<(ostream& fo, const PhanSo& ps);
};

int GCD(int, int);
