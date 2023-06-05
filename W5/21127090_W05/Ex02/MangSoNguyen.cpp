#include "MangSoNguyen.h"

MangSoNguyen::MangSoNguyen()
{
	kichthuoc = 0;
	dulieu = new int[kichthuoc];
}

MangSoNguyen::MangSoNguyen(int size)
{
	kichthuoc = size;
	dulieu = new int[size];
}

MangSoNguyen::MangSoNguyen(int* arr, int size)
{
	kichthuoc = size;
	dulieu = new int[size];
	for (int i = 0; i < size; i++)
	{
		dulieu[i] = arr[i];
	}
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& intArr)
{
	kichthuoc = intArr.kichthuoc;
	dulieu = new int[kichthuoc];
	for (int i = 0; i < kichthuoc; i++)
	{
		dulieu[i] = intArr.dulieu[i];
	}
}

MangSoNguyen::~MangSoNguyen()
{
	delete[] dulieu;
	dulieu = NULL;
	kichthuoc = 0;
}

MangSoNguyen& MangSoNguyen::operator=(const MangSoNguyen& intArr)
{
	if (this == &intArr)
	{
		return *this;
	}
	delete[]dulieu;
	this->kichthuoc = intArr.kichthuoc;
	this->dulieu = new int[this->kichthuoc];
	for (int i = 0; i < this->kichthuoc; i++)
	{
		this->dulieu[i] = intArr.dulieu[i];
	}
	return *this;
}

MangSoNguyen MangSoNguyen::operator+(const MangSoNguyen& intArr)
{
	int size = max(intArr.kichthuoc, this->kichthuoc);
	MangSoNguyen tmp(size);
	int i = 0, j = 0, k=0;
	while (i < intArr.kichthuoc && j < this->kichthuoc)
	{
		//*(tmp.dulieu+k) = *(this->dulieu + j) + *(intArr.dulieu + i);
		tmp.dulieu[k] = this->dulieu[j] + intArr.dulieu[i];
		k++;
		i++;
		j++;
	}
	while (i < intArr.kichthuoc)
	{
		tmp.dulieu[k] = intArr.dulieu[i];
		i++;
		k++;
	}

	while (j < this->kichthuoc)
	{
		tmp.dulieu[k] = this->dulieu[j];
		j++;
		k++;
	}
	return tmp;
}

// a++
MangSoNguyen MangSoNguyen::operator++(int x)
{
	MangSoNguyen tmp(*this);
	for (int i = 0; i < this->kichthuoc; i++)
	{
		this->dulieu[i]++;
	}
	return tmp;
}

// ++a
MangSoNguyen& MangSoNguyen::operator++()
{
	for (int i = 0; i < kichthuoc; i++)
	{
		dulieu[i]++;
	}
	return *this;
}

istream& operator>>(istream& is, MangSoNguyen& intArr)
{
	cout << "Kich thuoc: ";
	is >> intArr.kichthuoc;
	intArr.dulieu = new int[intArr.kichthuoc];
	cout << "Du lieu: ";
	for (int i = 0; i < intArr.kichthuoc; i++)
	{
		is >> intArr.dulieu[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const MangSoNguyen& intArr)
{
	os << "Kich thuoc: " << intArr.kichthuoc << endl;
	os << "Du lieu: ";
	for (int i = 0; i < intArr.kichthuoc; i++)
	{
		os << intArr.dulieu[i] << " ";
	}
	cout << endl;
	return os;
}


