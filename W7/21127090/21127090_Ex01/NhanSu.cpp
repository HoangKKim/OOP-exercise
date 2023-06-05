#include "NhanSu.h"

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

void TroGiang::input()
{
	NhanSu::input();
	cout << "- So mon tro giang: ";
	cin >> somontrogiang;
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

void TruongHoc::input()
{
	int n;
	cout << "THONG TIN NHAN SU CUA TRUONG" << endl;
	cout << "a. So luong Giang Vien: ";
	cin >> n;
	dsGiangVien.resize(n);
	cin.ignore();
	for (int i = 0; i < dsGiangVien.size(); i++)
	{
		cout << "* GIANG VIEN " << i + 1 << endl;
		dsGiangVien[i].input();
		cout << endl;
	}
	cout << endl;

	cout << "b. So luong Tro Giang: ";
	cin >> n;
	cin.ignore();
	dsTroGiang.resize(n);
	for (int i = 0; i < dsTroGiang.size(); i++)
	{
		cout << "TRO GIANG " << i + 1 << endl;
		dsTroGiang[i].input();
		cin.ignore();
		cout << endl;
	}
	cout << endl;

	cout << "c. So luong Nghien Cuu Vien: ";
	cin >> n;
	cin.ignore();
	dsNghienCuuVien.resize(n);
	for (int i = 0; i < dsNghienCuuVien.size(); i++)
	{
		cout << "NGHIEN CUU VIEN: " << i + 1 << endl;
		dsNghienCuuVien[i].input();
		cout << endl;
	}
	cout << endl;

	cout << "d. So luong Chuyen Vien: ";
	cin >> n;
	cin.ignore();
	dsChuyenVien.resize(n);
	for (int i = 0; i < dsChuyenVien.size(); i++)
	{
		cout << "CHUYEN VIEN " << i + 1 << endl;
		dsChuyenVien[i].input();
		cout << endl;
	}
	cout << endl;
}

void TruongHoc::output()
{
	cout << "THONG TIN NHAN SU CUA TRUONG" << endl;
	cout << "a. So luong Giang Vien: " << dsGiangVien.size() << endl;
	for (int i = 0; i < dsGiangVien.size(); i++)
	{
		cout << "GIANG VIEN " << i + 1 << endl;
		dsGiangVien[i].output();
		cout << endl;
	}

	cout << "b. So luong Tro Giang: " << dsTroGiang.size() << endl;
	for (int i = 0; i < dsTroGiang.size(); i++)
	{
		cout << "TRO GIANG " << i + 1 << endl;
		dsTroGiang[i].output();
		cout << endl;
	}

	cout << "c. So luong Nghien Cuu Vien: " << dsNghienCuuVien.size() << endl;
	for (int i = 0; i < dsNghienCuuVien.size(); i++)
	{
		cout << "NGHIEN CUU VIEN " << i + 1 << endl;
		dsNghienCuuVien[i].output();
		cout << endl;
	}

	cout << "d. So luong Chuyen Vien: " << dsChuyenVien.size() << endl;
	for (int i = 0; i < dsChuyenVien.size(); i++)
	{
		cout << "CHUYEN VIEN " << i + 1 << endl;
		dsChuyenVien[i].output();
		cout << endl;
	}
}

float TruongHoc::calcLuong()
{
	float tmp = 0;
	for (int i = 0; i < dsGiangVien.size(); i++)
	{
		dsGiangVien[i].setLuong();
		tmp = tmp + dsGiangVien[i].getLuong();
	}

	for (int i = 0; i < dsTroGiang.size(); i++)
	{
		dsTroGiang[i].setLuong();
		tmp = tmp + dsTroGiang[i].getLuong();
	}

	for (int i = 0; i < dsNghienCuuVien.size(); i++)
	{
		dsNghienCuuVien[i].setLuong();
		tmp = tmp + dsNghienCuuVien[i].getLuong();
	}

	for (int i = 0; i < dsChuyenVien.size(); i++)
	{
		dsChuyenVien[i].setLuong();
		tmp = tmp + dsChuyenVien[i].getLuong();
	}

	return tmp;
}

TruongHoc::~TruongHoc()
{
	for (int i = 0; i < dsGiangVien.size(); i++)
	{
		dsGiangVien[i].~GiangVien();
	}
	dsGiangVien.clear();
	dsGiangVien.resize(0);

	for (int i = 0; i < dsTroGiang.size(); i++)
	{
		dsTroGiang[i].~TroGiang();
	}
	dsTroGiang.clear();
	dsTroGiang.resize(0);

	for (int i = 0; i < dsNghienCuuVien.size(); i++)
	{
		dsNghienCuuVien[i].~NghienCuuVien();
	}
	dsNghienCuuVien.clear();
	dsNghienCuuVien.resize(0);

	for (int i = 0; i < dsChuyenVien.size(); i++)
	{
		dsChuyenVien[i].~ChuyenVien();
	}
	dsChuyenVien.clear();
	dsChuyenVien.resize(0);
}