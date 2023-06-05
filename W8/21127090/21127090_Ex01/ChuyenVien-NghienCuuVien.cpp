#include "NhanSu.h"

NghienCuuVien::NghienCuuVien() : NhanSu()
{
	sonamkinhnghiem = 0;
	maduan_NCV.resize(0);
}
NghienCuuVien::NghienCuuVien(string hoten, string ngaysinh, string masoNS, vector <string> maDA, int sonamKN) :
	NhanSu(hoten, ngaysinh, masoNS)
{
	sonamkinhnghiem = sonamKN;
	maduan_NCV.resize(maDA.size());
	for (int i = 0; i < maduan_NCV.size(); i++)
	{
		maduan_NCV[i] = maDA[i];
	}
}

string NghienCuuVien::getNameClass()
{
	return "NGHIEN CUU VIEN";
}

void NghienCuuVien::input()
{
	int n;
	NhanSu::input();
	cout << "- So nam kinh nghiem nghien cuu: ";
	cin >> sonamkinhnghiem;
	cout << "- So du an dang tham gia: ";
	cin >> n;
	maduan_NCV.resize(n);
	cout << "- Danh sach cac ma du an, moi ma du an bat dau bang mot chu cai in hoa va 2 chu so " << endl;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "+ Du an " << i + 1 << ": ";
		getline(cin, maduan_NCV[i]);
	}
}

void NghienCuuVien::setLuong()
{
	int count = 0;
	for (int i = 0; i < maduan_NCV.size(); i++)
	{
		if (maduan_NCV[i].at(0) == 'D')
		{
			count++;
		}
	}
	this->luong = (sonamkinhnghiem * 2 + count) * 20000;
}

void NghienCuuVien::output()
{
	NhanSu::output();
	cout << "- So nam kinh nghiem nghien cuu: " << sonamkinhnghiem << endl;
	cout << "- So du an dang tham gia: " << maduan_NCV.size() << endl;
	cout << "- Danh sach cac ma du an " << endl;
	for (int i = 0; i < maduan_NCV.size(); i++)
	{
		cout << "+ Du an " << i + 1 << ": " << maduan_NCV[i] << endl;
	}
}

NghienCuuVien::~NghienCuuVien()
{
	NhanSu::~NhanSu();
	sonamkinhnghiem = 0;
	maduan_NCV.clear();
	maduan_NCV.resize(0);
}

ChuyenVien::ChuyenVien() :NhanSu()
{
	sonamkinhnghiem = 0;
	maduan_CV.resize(0);
}

ChuyenVien::ChuyenVien(string hoten, string ngaysinh, string masoNS, vector <string> maDA, int sonamKN) :
	NhanSu(hoten, ngaysinh, masoNS)
{
	sonamkinhnghiem = sonamKN;
	maduan_CV.resize(maDA.size());
	for (int i = 0; i < maduan_CV.size(); i++)
	{
		maduan_CV[i] = maDA[i];
	}
}

string ChuyenVien::getNameClass()
{
	return "CHUYEN VIEN";
}

void ChuyenVien::input()
{
	int n;
	NhanSu::input();
	cout << "- So nam kinh nghiem lam viec: ";
	cin >> sonamkinhnghiem;
	cout << "- So du an giao duc da hoan thanh: ";
	cin >> n;
	maduan_CV.resize(n);
	cout << "- Danh sach cac ma du an giao duc da hoan thanh " << endl;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "+Du an " << i + 1 << ": ";
		getline(cin, maduan_CV[i]);
	}
}

void ChuyenVien::setLuong()
{
	int count = 0;
	for (int i = 0; i < maduan_CV.size(); i++)
	{
		if (maduan_CV[i].at(0) == 'T')
		{
			count++;
		}
	}
	this->luong = (sonamkinhnghiem * 4 + count) * 18000;
}

void ChuyenVien::output()
{
	NhanSu::output();
	cout << "- So nam kinh nghiem lam viec: " << sonamkinhnghiem << endl;
	cout << "- So du an giao duc da hoan thanh: " << maduan_CV.size() << endl;
	cout << "- Danh sach cac ma du an giao duc da hoan thanh " << endl;
	for (int i = 0; i < maduan_CV.size(); i++)
	{
		cout << "+ Du an " << i + 1 << ": " << maduan_CV[i] << endl;
	}
}

ChuyenVien::~ChuyenVien()
{
	NhanSu::~NhanSu();
	sonamkinhnghiem = 0;
	maduan_CV.clear();
	maduan_CV.resize(0);
}
