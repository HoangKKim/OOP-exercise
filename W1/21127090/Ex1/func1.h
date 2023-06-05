#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Fraction
{
private:
	int numerator, denominator;
public:
	void input();
	void output1();
	void output2();
	void reduce();
	void add(Fraction frac1, Fraction frac2);
	void subtract(Fraction frac1, Fraction frac2);
	void multiply(Fraction frac1, Fraction frac2);
	void divide(Fraction frac1, Fraction frac2);
};

int GCD(int a, int b);

