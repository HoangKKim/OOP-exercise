#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanSu
{
protected:
	string hoten;
	string ngaysinh;
	string maso;
	float luong;
public:
	NhanSu()
	{
		hoten = '\0';
		ngaysinh = '\0';
		maso = '\0';
		luong = 0;
	}
	NhanSu(string name, string birthday, string masoNS)
	{
		hoten = name;
		ngaysinh = birthday;
		maso = masoNS;
	}
	void input();
	void output();
	virtual void setLuong() = 0;
	float getLuong();
	~NhanSu()
	{
		hoten = '\0';
		ngaysinh = '\0';
		maso = '\0';
		luong = 0;
	}
};

class GiangVien :public NhanSu
{
private:
	string hocham;
	string hocvi;
	int sonamgiangday;
	vector <string> dsMonHoc;
public:
	GiangVien() : NhanSu()
	{
		hocham = '\0';
		hocvi = '\0';
		sonamgiangday = 0;
		dsMonHoc.resize(0);
	}
	GiangVien(string hoten, string ngaysinh, string masoNS,string hham, string hvi, int sonamgd, vector <string> ds):
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
	void setLuong();
	void input();
	void output();
	~GiangVien()
	{
		NhanSu::~NhanSu();
		hocham = '\0';
		hocvi = '\0';
		sonamgiangday = 0;
		dsMonHoc.clear();
		dsMonHoc.resize(0);
	}

};

class TroGiang :public NhanSu
{
private:
	int somontrogiang;
public:
	TroGiang(): NhanSu()
	{
		somontrogiang = 0;
	}
	TroGiang(string hoten, string ngaysinh, string masoNS, int somonTG) :
		NhanSu(hoten, ngaysinh, masoNS)
	{
		somontrogiang = somonTG;
	}
	void setLuong();
	void input();
	void output();
	~TroGiang()
	{
		NhanSu::~NhanSu();
		somontrogiang = 0;
	}
};

class NghienCuuVien :public NhanSu
{
private:
	vector <string> maduan_NCV;
	int sonamkinhnghiem;
public:
	NghienCuuVien(): NhanSu()
	{
		sonamkinhnghiem = 0;
		maduan_NCV.resize(0);
	}
	NghienCuuVien(string hoten, string ngaysinh, string masoNS, vector <string> maDA, int sonamKN) :
		NhanSu(hoten, ngaysinh, masoNS)
	{
		sonamkinhnghiem = sonamKN;
		maduan_NCV.resize(maDA.size());
		for (int i = 0; i < maduan_NCV.size(); i++)
		{
			maduan_NCV[i] = maDA[i];
		}
	}
	void setLuong();
	void input();
	void output(); 
	~NghienCuuVien()
	{
		NhanSu::~NhanSu();
		sonamkinhnghiem = 0;
		maduan_NCV.clear();
		maduan_NCV.resize(0);
	}
};

class ChuyenVien :public NhanSu
{
private:
	vector <string> maduan_CV;
	int sonamkinhnghiem;
public:
	ChuyenVien() :NhanSu()
	{
		sonamkinhnghiem = 0;
		maduan_CV.resize(0);
	}
	ChuyenVien(string hoten, string ngaysinh, string masoNS, vector <string> maDA, int sonamKN) :
		NhanSu(hoten, ngaysinh, masoNS)
	{
		sonamkinhnghiem = sonamKN;
		maduan_CV.resize(maDA.size());
		for (int i = 0; i < maduan_CV.size(); i++)
		{
			maduan_CV[i] = maDA[i];
		}
	}
	void setLuong();
	void input();
	void output();
	~ChuyenVien()
	{
		NhanSu::~NhanSu();
		sonamkinhnghiem = 0;
		maduan_CV.clear();
		maduan_CV.resize(0);
	}
};

class TruongHoc
{
private:
	vector<GiangVien> dsGiangVien;
	vector<TroGiang> dsTroGiang;
	vector<NghienCuuVien> dsNghienCuuVien;
	vector<ChuyenVien> dsChuyenVien;
public:
	TruongHoc()
	{
		dsGiangVien.resize(0);
		dsTroGiang.resize(0);
		dsNghienCuuVien.resize(0);
		dsChuyenVien.resize(0);
	}
	void input();
	void output();
	float calcLuong();
	~TruongHoc();
	

};
