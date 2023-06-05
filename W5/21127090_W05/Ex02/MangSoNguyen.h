#pragma once
#include <iostream>

using namespace std;

class MangSoNguyen
{
private:
	int* dulieu;
	int kichthuoc;
public:
	//constructor - destructor
	MangSoNguyen();
	MangSoNguyen(int size);
	MangSoNguyen(int*, int);
	MangSoNguyen(const MangSoNguyen& intArr);
	~MangSoNguyen();

	// overloading operator +, =, ++,>>, << 
	MangSoNguyen& operator=(const MangSoNguyen& intArr);
	MangSoNguyen operator+(const MangSoNguyen& intArr);
	// a++ : hau to 
	MangSoNguyen operator++(int);
	// ++a: tien to 
	MangSoNguyen& operator++();
	friend istream& operator>>(istream& is, MangSoNguyen& intArr);
	friend ostream& operator<<(ostream& os, const MangSoNguyen& intArr);
};

