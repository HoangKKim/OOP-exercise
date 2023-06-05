#include "NhanSu.h"

ThucTapSinh::ThucTapSinh() :NhanSu()
{
	maduan_dubi.resize(0);
	tgThucTap = 0;
}
ThucTapSinh::ThucTapSinh(string hoten, string ngaysinh, string masoNS, int init_tgThucTap, vector <string> duan) :
	NhanSu(hoten, ngaysinh, masoNS)
{
	tgThucTap = init_tgThucTap;
	maduan_dubi.resize(duan.size());
	for (int i = 0; i < maduan_dubi.size(); i++)
	{
		maduan_dubi[i] = duan[i];
	}
}
string ThucTapSinh::getNameClass()
{
	return "THUC TAP SINH";
}

void ThucTapSinh::setLuong()
{
	int count = 0;
	for (int i = 0; i < maduan_dubi.size(); i++)
	{
		if (maduan_dubi[i].at(0) == 'R')
		{
			count++;
		}
	}
	this->luong = 0.1 * count * 10000;
}

void ThucTapSinh::input()
{
	NhanSu::input();
	int n;
	cout << "- So thang thuc tap: ";
	cin >> tgThucTap;
	cout << "- So du an nghien cuu du bi: ";
	cin >> n;
	maduan_dubi.resize(n);
	cout << "- Danh sach cac ma du an, moi ma du an bat dau bang mot chu cai in hoa va 2 chu so " << endl;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "+ Du an " << i + 1 << ": ";
		getline(cin, maduan_dubi[i]);
	}
}

void ThucTapSinh::output()
{
	NhanSu::output();
	cout << "- So thang thuc tap: " << tgThucTap << endl;
	cout << "- So du an du bi dang tham gia: " << maduan_dubi.size() << endl;
	cout << "- Danh sach cac ma du an " << endl;
	for (int i = 0; i < maduan_dubi.size(); i++)
	{
		cout << "+ Du an " << i + 1 << ": " << maduan_dubi[i] << endl;
	}
}

ThucTapSinh::~ThucTapSinh()
{
	tgThucTap = 0;
	for (int i = 0; i < maduan_dubi.size(); i++)
	{
		maduan_dubi[i].clear();
	}
	maduan_dubi.clear();
}