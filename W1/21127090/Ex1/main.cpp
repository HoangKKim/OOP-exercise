#include "func1.h"

int main()
{
	Fraction frac1, frac2, result;
	cout << "Input fraction 1: " << endl;
	frac1.input();
	cout << endl;

	cout << "Input fraction 2: " << endl;
	frac2.input();
	cout << endl;

	result.add(frac1, frac2);
	result.reduce();
	cout << "Addition: ";
	result.output1();
	result.output2();
	cout << endl;

	result.subtract(frac1, frac2);
	result.reduce();
	cout << "Subtraction: ";
	result.output1();
	result.output2();
	cout << endl;

	result.multiply(frac1, frac2);
	result.reduce();
	cout << "Multiplication: ";
	result.output1();
	result.output2();
	cout << endl;

	result.divide(frac1, frac2);
	result.reduce();
	cout << "Division: ";
	result.output1();
	result.output2();
	cout << endl;
}