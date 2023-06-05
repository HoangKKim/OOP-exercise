#include "func1.h"

void Fraction::input()
{
	do
	{
		cout << "Input numerator: ";
		cin >> numerator;
		cout << "Input denominator: ";
		cin >> denominator;
		if (denominator == 0)
		{
			cout << endl << "Invalid denominator! Input again" << endl;
		}
	} while (denominator == 0);
}

void Fraction::output1()
{
	if ((numerator < 0 && denominator < 0) || (denominator < 0))
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	cout << numerator << "/" << denominator << endl;
}

void Fraction::output2()
{
	float result = (float)numerator / (float)denominator;
	cout << setprecision(2) << fixed << result << endl;
}

void Fraction::add(Fraction frac1, Fraction frac2)
{
	Fraction tmp;
	if (frac1.denominator == frac2.denominator)
	{
		this->denominator = frac1.denominator;
		this->numerator = frac1.numerator + frac2.numerator;
	}
	else
	{
		this->denominator = frac1.denominator * frac2.denominator;
		this->numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
	}
}

void Fraction::subtract(Fraction frac1, Fraction frac2)
{
	if (frac1.denominator == frac2.denominator)
	{
		this->denominator = frac1.denominator;
		this->numerator = frac1.numerator - frac2.numerator;
	}
	else
	{
		this->denominator = frac1.denominator * frac2.denominator;
		this->numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
	}
}

void Fraction::multiply(Fraction frac1, Fraction frac2)
{
	Fraction tmp;
	this->denominator = frac1.denominator * frac2.denominator;
	this->numerator = frac1.numerator * frac2.numerator;
}

void Fraction::divide(Fraction frac1, Fraction frac2)
{
	this->denominator = frac1.denominator * frac2.numerator;
	this->numerator = frac1.numerator * frac2.denominator;
}

void Fraction::reduce()
{
	int gcd = GCD(this->numerator, this->denominator);
	this->numerator = this->numerator / gcd;
	this->denominator = this->denominator / gcd;
}

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return GCD(b, a % b);
}