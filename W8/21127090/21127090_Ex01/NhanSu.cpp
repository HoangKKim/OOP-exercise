#include "NhanSu.h"

NhanSu::NhanSu()
{
	hoten = '\0';
	ngaysinh = '\0';
	maso = '\0';
	luong = 0;
}

NhanSu::NhanSu(string name, string birthday, string masoNS)
{
	hoten = name;
	ngaysinh = birthday;
	maso = masoNS;
}

NhanSu::~NhanSu()
{
	hoten.clear();
	ngaysinh.clear();
	maso.clear();
	luong = 0;
}

void NhanSu::input()
{
	cout << "- Ho ten: ";
	getline(cin, hoten);
	cout << "- Ngay thang nam sinh: ";
	getline(cin, ngaysinh);
	cout << "- Ma so nhan su: ";
	getline(cin, maso);
}

void NhanSu::output()
{
	cout << "- Ho ten: " << hoten << endl;
	cout << "- Ngay thang nam sinh: " << ngaysinh << endl;
	cout << "- Ma so nhan su: " << maso << endl;
}

float NhanSu::getLuong()
{
	return this->luong;
}

TruongHoc::TruongHoc()
{
	dsNhanSu.resize(0);
}

TruongHoc::TruongHoc(vector <NhanSu*>m_dsNhanSu)
{
	dsNhanSu.resize(m_dsNhanSu.size());
	for (int i = 0; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i] = m_dsNhanSu[i];
	}
}
	
TruongHoc::TruongHoc(const TruongHoc& mTruongHoc)
{
	for (int i = 0; i < dsNhanSu.size(); i++)
	{
		delete dsNhanSu[i];
	}
	dsNhanSu.clear();

	dsNhanSu.resize(mTruongHoc.dsNhanSu.size());
	for (int i = 0; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i] = mTruongHoc.dsNhanSu[i];
	}
}

void TruongHoc::input()
{
	int n, i = 0;
	cout << "THONG TIN NHAN SU CUA TRUONG" << endl;
	cout << "a. So luong Giang Vien: ";
	cin >> n;
	dsNhanSu.resize(n);
	cin.ignore();
	for ( i ; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i] = new GiangVien;
		dsNhanSu[i]->input();
		cout << endl;
	}
	cout << endl;

	cout << "b. So luong Tro Giang: ";
	cin >> n;
	cin.ignore();
	dsNhanSu.resize(n+dsNhanSu.size());
	for (i; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i]= new TroGiang;
		dsNhanSu[i]->input();
		cin.ignore();
		cout << endl;
	}
	cout << endl;

	cout << "c. So luong Nghien Cuu Vien: ";
	cin >> n;
	cin.ignore();
	dsNhanSu.resize(n + dsNhanSu.size());
	for (i; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i] = new NghienCuuVien;
		dsNhanSu[i]->input();
		cout << endl;
	}
	cout << endl;

	cout << "d. So luong Chuyen Vien: ";
	cin >> n;
	cin.ignore();
	dsNhanSu.resize(n + dsNhanSu.size());
	for (i; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i] = new ChuyenVien;
		dsNhanSu[i]->input();
		cout << endl;
	}
	cout << endl;

	cout << "e. So luong Thuc tap sinh: ";
	cin >> n;
	cin.ignore();
	dsNhanSu.resize(n + dsNhanSu.size());
	for (i; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i] = new ThucTapSinh;
		dsNhanSu[i]->input();
		cout << endl;
	}
	cout << endl;
}

void TruongHoc::output()
{
	if (dsNhanSu.size() == 0)
	{
		return;
	}
	cout << "THONG TIN NHAN SU CUA TRUONG" << endl;
	for (int i = 0; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i]->getNameClass();
		cout << endl;
		dsNhanSu[i]->output();
		cout << endl;
	}
}

float TruongHoc::calcLuong()
{
	float tmp = 0;
	for (int i = 0; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i]->setLuong();
		tmp = tmp + dsNhanSu[i]->getLuong();
	}
	return tmp;
}

void TruongHoc::highestLuong()
{
	if (dsNhanSu.size() == 0)
	{
		return;
	}
	int max = 0, pos = 0;
	for (int i = 0; i < dsNhanSu.size(); i++)
	{
		if (dsNhanSu[i]->getLuong() > max)
		{
			max = dsNhanSu[i]->getLuong();
			pos = i;
		}
	}
	cout << "Thong tin nhan su co luong cao nhat " << endl;
	dsNhanSu[pos]->getNameClass();
	cout << endl;
	dsNhanSu[pos]->output();
}

TruongHoc::~TruongHoc()
{
	for (int i = 0; i < dsNhanSu.size(); i++)
	{
		dsNhanSu[i]->~NhanSu();
		delete dsNhanSu[i];
		dsNhanSu[i] = nullptr;
	}
	dsNhanSu.clear();
}
