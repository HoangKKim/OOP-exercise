#pragma once
#include <iostream>

using namespace std;

class PhanSo
{
private:
	int* tuso;
	int* mauso;
public:
	PhanSo();
	PhanSo(int, int);
	PhanSo(const PhanSo&);
	~PhanSo();

	PhanSo& operator=(const PhanSo& ps);
	PhanSo operator+(const PhanSo& ps);
	PhanSo operator-(const PhanSo& ps);
	PhanSo operator*(const PhanSo& ps);
	PhanSo operator/(const PhanSo& ps);

	PhanSo& operator+=(const PhanSo& ps);
	PhanSo& operator-=(const PhanSo& ps);
	PhanSo& operator*=(const PhanSo& ps);
	PhanSo& operator/=(const PhanSo& ps);

	bool operator==(const PhanSo& ps);
	bool operator<(const PhanSo& ps);
	bool operator>(const PhanSo& ps);
	bool operator<=(const PhanSo& ps);
	bool operator>=(const PhanSo& ps);
	bool operator!=(const PhanSo& ps);

	// tien to
	PhanSo& operator++();
	//hau to
	PhanSo operator++(int x);
	// tien to
	PhanSo& operator--();
	//hau to
	PhanSo operator--(int x);

	friend istream& operator>>(istream& is, PhanSo& ps);
	friend ostream& operator<<(ostream& os, const PhanSo& ps);

	void reduce();
};

int GCD(int, int);

