#include "func1.h"

// constructor
PhanSo::PhanSo() // default
{
	tuso = new int;
	mauso = new int;

	*tuso = 0;
	*mauso = 1;
}

PhanSo::PhanSo(int numer) // one parameter
{
	tuso = new int;
	mauso = new int;

	tuso = &numer;
}

PhanSo::PhanSo(int numer, int denom) // two parameters 
{
	tuso = new int;
	mauso = new int;

	tuso = &numer;
	mauso = &denom;
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

	tuso = NULL;
	mauso = NULL;
}

void PhanSo::setNumerator(int numer)
{
	*tuso = numer;
}

void PhanSo::setDenominator(int denom)
{
	*mauso = denom;
}

int PhanSo::getNumerator()
{
	return *tuso;
}

int PhanSo::getDenominator()
{
	return *mauso;
}

PhanSo& PhanSo::operator=(const PhanSo& a)
{
	delete tuso;
	delete mauso;
	tuso = new int;
	mauso = new int;

	if (this == &a)
	{
		return *this;
	}

	*tuso = *a.tuso;
	*mauso = *a.mauso;
	return *this;
}

PhanSo operator+(const PhanSo& a, const PhanSo& b)
{
	PhanSo res;
	if (*a.mauso == *b.mauso)
	{
		*res.tuso = *a.tuso + *b.tuso;
		*res.mauso = *a.mauso;
	}
	else
	{
		*res.tuso= *a.tuso * *b.mauso + *b.tuso * *a.mauso;
		*res.mauso = *a.mauso * *b.mauso;
	}
	res.reduce();
	return res;
}

PhanSo operator-(const PhanSo& a, const PhanSo& b)
{
	PhanSo res;
	if (*a.mauso == *b.mauso)
	{
		*res.tuso = *a.tuso - *b.tuso;
		*res.mauso = *a.mauso;
	}
	else
	{
		*res.tuso = *a.tuso * *b.mauso - *b.tuso * *a.mauso;
		*res.mauso = *a.mauso * *b.mauso;
	}
	res.reduce();
	return res;
}

PhanSo operator*(const PhanSo& a, const PhanSo& b)
{
	PhanSo res;
	*res.tuso = *a.tuso * *b.tuso;
	*res.mauso = *a.mauso * *b.mauso;
	res.reduce();
	return res;
}

PhanSo operator/(const PhanSo& a, const PhanSo& b)
{
	PhanSo res;
	*res.tuso = *a.tuso * *b.mauso;
	*res.mauso = *a.mauso * *b.tuso;
	res.reduce();
	return res;

}

istream& operator>>(istream& fi,const PhanSo& ps)
{
	char tmp='\0';
	do
	{
		if (tmp != '\0')
		{
			cout << "Phan so khong hop le! Xin nhap lai: " << endl;
		}
		fi >> *ps.tuso >> tmp >> *ps.mauso;
		

	} while (*ps.mauso == 0);
	return fi;
}

ostream& operator<<(ostream& fo, const PhanSo& ps)
{
	fo << *ps.tuso << '/' << *ps.mauso;
	return fo;
}

void PhanSo::output1()
{
	if ((*tuso < 0 && *mauso < 0) || (*mauso < 0))
	{
		*tuso = -*tuso;
		*mauso = -*mauso;
	}
	cout << *this << endl;
}

void PhanSo::output2()
{
	float result = (float)*tuso / (float)*mauso;
	cout << setprecision(2) << fixed << result << endl;
}

void PhanSo::reduce()
{
	int gcd = GCD(*tuso, *mauso);
	*tuso= *tuso / gcd;
	*mauso = *mauso/ gcd;
}

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return GCD(b, a % b);
}
