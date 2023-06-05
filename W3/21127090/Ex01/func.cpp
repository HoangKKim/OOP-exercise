#include "func.h"

// getter
string NhanVien::getName()
{
	return this->name;
}

int NhanVien::getWorkingDays()
{
	return this->workingDays;
}

string NhanVien::getID()
{
	return this->id;
}

string NhanVien::getPos()
{
	return this->pos;
}

float NhanVien::getcoeffiPay()
{
	return this->coeffiPay;
}

// setter
void NhanVien::setName(string name)
{
	this->name = name;
}

void NhanVien::setID(string id)
{
	this->id = id;
}

void NhanVien::setPos(string pos)
{
	this->pos = pos;
}

void NhanVien::setWorkingDays(int workingdays)
{
	this->workingDays = workingDays;
}

void NhanVien::setcoeffiPay(float coeffiPay)
{
	this->coeffiPay = coeffiPay;
}

// constructor
NhanVien::NhanVien()
{
	name = '\0';
	workingDays = 0;
	id = '\0';
	pos = "Nhan Vien";
	coeffiPay = 1.0;
}

NhanVien::NhanVien(string name, int workingDays, string id, string pos, float coeffiPay)
{
	this->name = name;
	this->workingDays = workingDays;
	this->id = id;
	this->pos = pos;
	this->coeffiPay = coeffiPay;
}

string convertNumberToString(int x)
{
	string s;
	while (x != 0)
	{
		int tmp = x % 10;
		char c = (tmp + 48);
		s = c + s;
		x = x / 10;
	}
	return s;
}

NhanVien::NhanVien(string name, int workingDays)
{
	this->name = name;
	this->workingDays = workingDays;
	string tmp = convertNumberToString(workingDays);
	this->id = tmp + name;
	if (workingDays < 365)
	{
		this->pos = "Nhan vien";
		this->coeffiPay = 1.0;
	}
	else if (workingDays >= 365 && workingDays < 730)
	{
		this->pos = "Quan ly";
		this->coeffiPay = 1.5;
	}
	else if (workingDays >= 730 && workingDays <= 1460)
	{
		this->pos = "Truong phong";
		this->coeffiPay = 2.25;
	}
	else
	{
		this->pos = "Truong ban quan ly";
		this->coeffiPay = 4.0;
	}
}

NhanVien::NhanVien(const NhanVien& nhanvien)
{
	this->pos = nhanvien.pos;
	this->coeffiPay = nhanvien.coeffiPay;
	this->workingDays = nhanvien.workingDays;
}

NhanVien::~NhanVien()
{
	name = '\0';
	workingDays = 0;
	id = '\0';
	pos = '\0';
	coeffiPay = 0;
}

void NhanVien::input()
{
	
	cout << "Name: ";
	getline(cin, name);
	cout << "Number of working days: ";
	cin >> workingDays;
	cout << "Position: ";
	cin.ignore();
	getline(cin, pos);
	cout << "ID: ";
	getline(cin, id);
	cout << "Coefficient pay: ";
	cin >> coeffiPay;
}

void NhanVien::output()
{
	cout << "Name: " << name << endl;
	cout << "Number of working days: " << workingDays << endl;
	cout << "ID: " << id << endl;
	cout << "Position: " << pos << endl;
	cout << "Coefficent pay: " << setprecision(2) << fixed << coeffiPay << endl;
	cout << endl;
}