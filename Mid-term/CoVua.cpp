#include "CoVua.h"
#include <iostream>
// khoi tao
Diem::Diem()
{
	/*x = new int;
	y = new int;
	*x = 0;
	*y = 0;*/
	x = 0;
	y = 0;
}

Diem::Diem(int m_x, int m_y)
{
	/*x = new int;
	y = new int;
	*x = m_x;
	*y = m_y;*/
	x = m_x;
	y = m_y;
}

// toan tu >>
istream& operator>>(istream& is, Diem& point)
{
	cout << "Nhap toa do x va y: ";
	is >> point.x >> point.y;
	return is;
}

// toan tu <<
ostream& operator<<(ostream& os, const Diem& point)
{
	os << "Toa do: (" << point.x << ";" << point.y << ")" << endl;
	return os;
}

// ham set quan co
void Diem::setQuanCo(int m_x, int m_y)
{
	//*this->x = m_x;
	//*this->y = m_y;
	x = m_x;
	y = m_y;
}

// ham get toa do x
int Diem::getX()
{
	return x;
}
// ham get toa do y
int Diem::getY()
{
	return y;
}

// toan tu =
Diem Diem::operator=(const Diem& point)
{
	/*Diem tmp;
	tmp.x = point.x;
	tmp.y = point.y;*/
	this->x = point.x;
	this->y = point.y;
	return *this;
}

// ham huy
Diem::~Diem()
{
	x = 0;
	y = 0;
}

// ham khoi tao
QuanCo::QuanCo()
{
	tenQuanCo = '\0';
	vitri_hientai.setQuanCo(0, 0);
	duongdi.push_back(vitri_hientai);
}

QuanCo::QuanCo(string name, vector <Diem> path, Diem currentPoint)
{
	tenQuanCo = name;
	vitri_hientai = currentPoint;
	for (int i = 0; i < path.size(); i++)
	{
		duongdi.push_back(path[i]);
	}
	duongdi.resize(path.size());
}

QuanCo::QuanCo(const QuanCo& src_QC)
{
	tenQuanCo = src_QC.tenQuanCo;
	vitri_hientai= src_QC.vitri_hientai;
	for (int i = 0; i < src_QC.duongdi.size(); i++)
	{
		duongdi.push_back(src_QC.duongdi[i]);
	}
	duongdi.resize(src_QC.duongdi.size());
}

// ham nhap
void QuanCo::input()
{
	int n;
	Diem tmp;
	cout << "Ten quan co: ";
	//cin.ignore();
	cin >> tenQuanCo;
	cout << "Vi tri quan co: " << endl;;
	cin >> vitri_hientai;
	cout << "Nhap so luong cac diem (nuoc di) ma quan co co: ";
	cin >> n;
	duongdi.resize(n);
	cout << "Cac diem nuoc di cua quan co: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Diem " << i + 1 << ": ";
		cin >> duongdi[i];
		//cin >> tmp;
		//duongdi.push_back(tmp);
	}
	
}

// ham xuat
void QuanCo::output()
{
	cout << "Ten quan co: " << tenQuanCo << endl;
	cout << "Vi tri quan co: " << vitri_hientai << endl;
	for (int i = 0; i < duongdi.size(); i++)
	{
		cout << duongdi[i] << endl;
	}
}

// ham tim khoang cach ngan nhat
float minPath(Diem A, Diem B)
{
	return sqrt(((A.getX() - B.getX()) * (A.getX() - B.getX())) + ((A.getY() - B.getY()) * (A.getY() - B.getY())));
}

// ham phong cap
bool QuanCo::PhongCap(vector<QuanCo> QC_doiphuong)
{
	vector <float> tmp;
	Diem tmp2;
	if ((vitri_hientai.getY() == 7) && (vitri_hientai.getX() >= 0 || vitri_hientai.getX() <= 7))
	{
		for (int i = 0; i < QC_doiphuong.size(); i++)
		{
			tmp2.setQuanCo(QC_doiphuong[i].duongdi[i].getX(), QC_doiphuong[i].duongdi[i].getY());
			tmp.push_back(minPath(vitri_hientai, tmp2));
		}
		float min = tmp[0]; 
		int pos = 0;
		for (int i = 1; i < QC_doiphuong.size()-1; i++)
		{
			if (tmp[i] < min)
			{
				min = tmp[i];
				pos = i;
			}
		}
		for (int i = 0; i < QC_doiphuong[pos].duongdi.size(); i++)
		{
			duongdi[i] = QC_doiphuong[pos].duongdi[i];
		}
		return true;
	}
	return false;
}
