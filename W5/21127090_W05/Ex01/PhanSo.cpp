#include "PhanSo.h"

PhanSo::PhanSo()
{
	tuso = new int;
	mauso = new int;
	*tuso = 0;
	*mauso = 1;
}

PhanSo::PhanSo(int t, int m)
{
	tuso = new int;
	mauso = new int;
	*tuso = t;
	*mauso = m;
}

PhanSo::PhanSo(const PhanSo& ps)
{
	tuso = new int;
	mauso = new int;
	*tuso = *ps.tuso;
	*mauso = *ps.mauso;
}

PhanSo::~PhanSo()
{
	delete tuso;
	delete mauso;
	tuso = nullptr;
	mauso = nullptr;
}

PhanSo& PhanSo::operator=(const PhanSo& ps)
{
	
	if (this == &ps)
	{
		return *this;
	} 
	delete tuso;
	delete mauso;
	tuso = new int;
	mauso = new int;
	*tuso = *ps.tuso;
	*mauso = *ps.mauso;
}

PhanSo PhanSo::operator+(const PhanSo& ps)
{
	PhanSo kq;
	*kq.tuso = *this->tuso * *ps.mauso + *this->mauso * *ps.tuso;
	*kq.mauso = *this->mauso * *ps.mauso;
	kq.reduce();
	return kq;
}

PhanSo PhanSo::operator-(const PhanSo& ps)
{
	PhanSo kq;
	*kq.tuso = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	*kq.mauso = *this->mauso * *ps.mauso;
	kq.reduce();
	return kq;
}

PhanSo PhanSo::operator*(const PhanSo& ps)
{
	PhanSo kq;
	*kq.tuso = *this->tuso * *ps.tuso;
	*kq.mauso = *this->mauso * *ps.mauso;
	kq.reduce();
	return kq;
}

PhanSo PhanSo::operator/(const PhanSo& ps)
{
	PhanSo kq;
	*kq.tuso = *this->tuso *  *ps.mauso;
	*kq.mauso = *this->mauso * *ps.tuso;
	kq.reduce();
	return kq;
}

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return GCD(b,a % b);
}

void PhanSo::reduce()
{
	int gcd = GCD(*tuso, *mauso);
	*tuso = *tuso / gcd;
	*mauso = *mauso / gcd;
}

PhanSo& PhanSo::operator+=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.mauso + *this->mauso * *ps.tuso;
	*this->mauso = *this->mauso * *ps.mauso;
	this->reduce();
	return *this;
}

PhanSo& PhanSo::operator-=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	*this->mauso = *this->mauso * *ps.mauso;
	this->reduce();
	return *this;
}

PhanSo& PhanSo::operator*=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.tuso;
	*this->mauso = *this->mauso * *ps.mauso;
	this->reduce();
	return *this;
}

PhanSo& PhanSo::operator/=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.mauso;
	*this->mauso = *this->mauso * *ps.tuso;
	this->reduce();
	return *this;
}

bool PhanSo::operator==(const PhanSo& ps)
{
	int result;
	result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	return (result == 0);
}

bool PhanSo::operator>(const PhanSo& ps)
{
	int result;
	result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	return (result > 0);
}

bool PhanSo::operator<(const PhanSo& ps)
{
	int result;
	result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	return (result < 0);
}

bool PhanSo::operator>=(const PhanSo& ps)
{
	int result;
	result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	return (result >= 0);
}

bool PhanSo::operator<=(const PhanSo& ps)
{
	int result;
	result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	return (result <= 0);
}

bool PhanSo::operator!=(const PhanSo& ps)
{
	int result;
	result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	return (result != 0);
}

// hau to a++: gan truoc xl sau
PhanSo PhanSo::operator++(int x)
{
	PhanSo tmp(*this);
	//*this->tuso = *this->tuso + *this->mauso;
	*this->tuso = *this->tuso + *this->mauso;
	return tmp;
}

// tien to: ++a
PhanSo& PhanSo::operator++()
{
	*this->tuso = *this->tuso + *this->mauso;
	return *this;
}

// hau to a--: gan truoc xl sau
PhanSo PhanSo::operator--(int x)
{
	PhanSo tmp(*this);
	//*this->tuso = *this->tuso + *this->mauso;
	*this->tuso = *this->tuso - *this->mauso;
	return tmp;
}

// tien to: --a
PhanSo& PhanSo::operator--()
{
	*this->tuso = *this->tuso - *this->mauso;
	return *this;
}

istream& operator>>(istream& is, PhanSo& ps) // coi lai co const khong
{
	char tmp = '\0';
	do
	{
		if (tmp != NULL)
		{
			cout << "Phan so khong hop le, xin nhap lai" << endl;
		}
		is >> *ps.tuso >> tmp >> *ps.mauso;
	} while (*ps.mauso == 0);
	return is;
}

ostream& operator<<(ostream& os, const PhanSo& ps)
{
	if ((* ps.tuso < 0 && *ps.mauso < 0) || (*ps.mauso<0))
	{
		*ps.tuso = -*ps.tuso;
		*ps.mauso = -*ps.mauso;
	}

	os << *ps.tuso << '/' << *ps.mauso;
	return os;
}
