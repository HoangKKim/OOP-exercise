#include "NhanSu.h"

GiangVien::GiangVien(string hoten, string ngaysinh, string masoNS, string hham, string hvi, int sonamgd, vector <string> ds) :
	NhanSu(hoten, ngaysinh, masoNS)
{
	hocham = hham;
	hocvi = hvi;
	sonamgiangday = sonamgd;
	dsMonHoc.resize(ds.size());
	for (int i = 0; i < ds.size(); i++)
	{
		dsMonHoc[i] = ds[i];
	}
}

GiangVien::GiangVien() : NhanSu()
{
	hocham = '\0';
	hocvi = '\0';
	sonamgiangday = 0;
	dsMonHoc.resize(0);
}

string GiangVien::getNameClass()
{
	return "GIANG VIEN";
}

void GiangVien::input()
{
	NhanSu::input();
	int n;
	cout << "- Hoc ham: ";
	getline(cin, hocham);
	cout << "- Hoc vi: ";
	getline(cin, hocvi);
	cout << "- So nam giang day: ";
	cin >> sonamgiangday;
	cout << "- So luong mon hoc dang giang day: ";
	cin >> n;
	dsMonHoc.resize(n);
	cout << "- Danh sach mon hoc: " << endl;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "+ Mon hoc " << i + 1 << ": ";
		getline(cin, dsMonHoc[i]);
	}
}

void GiangVien::setLuong()
{
	this->luong = (dsMonHoc.size() * sonamgiangday * 0.12) * 20000;
}

void GiangVien::output()
{
	NhanSu::output();
	cout << "- Hoc ham: " << hocham << endl;
	cout << "- Hoc vi: " << hocvi << endl;
	cout << "- So nam giang day: " << sonamgiangday << endl;
	cout << "- So luong mon hoc dang giang day: " << dsMonHoc.size() << endl;
	cout << "- Danh sach mon hoc " << endl;
	for (auto i = 0; i < dsMonHoc.size(); i++)
	{
		cout << "+ Mon hoc " << i + 1 << ": " << dsMonHoc[i] << endl;
	}
}

GiangVien::~GiangVien()
{
	NhanSu::~NhanSu();
	hocham.clear();
	hocvi.clear();
	sonamgiangday = 0;
	dsMonHoc.clear();
	dsMonHoc.resize(0);
}

TroGiang::TroGiang() : NhanSu()
{
	somontrogiang = 0;
}

TroGiang::TroGiang(string hoten, string ngaysinh, string masoNS, int somonTG) :
	NhanSu(hoten, ngaysinh, masoNS)
{
	somontrogiang = somonTG;
}

TroGiang::~TroGiang()
{
	NhanSu::~NhanSu();
	somontrogiang = 0;
}

void TroGiang::input()
{
	NhanSu::input();
	cout << "- So mon tro giang: ";
	cin >> somontrogiang;
}

string TroGiang::getNameClass()
{
	return "TRO GIANG";
}

void TroGiang::setLuong()
{
	this->luong = (somontrogiang * 0.3) * 18000;
}

void TroGiang::output()
{
	NhanSu::output();
	cout << "- So mon tro giang: " << somontrogiang << endl;
}
