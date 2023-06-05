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
	NhanSu();
	NhanSu(string name, string birthday, string masoNS);
	virtual void input();
	virtual void output();
	virtual void setLuong() = 0 ;
	float getLuong();
	virtual string getNameClass() = 0;
	virtual ~NhanSu();
};

class GiangVien :public NhanSu
{
private:
	string hocham;
	string hocvi;
	int sonamgiangday;
	vector <string> dsMonHoc;
public:
	GiangVien();
	GiangVien(string hoten, string ngaysinh, string masoNS, string hham, string hvi, int sonamgd, vector <string> ds);
	void setLuong();
	void input();
	void output();
	string getNameClass();
	~GiangVien();
};

class TroGiang :public NhanSu
{
private:
	int somontrogiang;
public:
	TroGiang();
	TroGiang(string hoten, string ngaysinh, string masoNS, int somonTG);
	void setLuong();
	void input();
	void output();
	string getNameClass();
	~TroGiang();
};

class NghienCuuVien :public NhanSu
{
private:
	vector <string> maduan_NCV;
	int sonamkinhnghiem;
public:
	NghienCuuVien();
	NghienCuuVien(string hoten, string ngaysinh, string masoNS, vector <string> maDA, int sonamKN); 
	void setLuong();
	void input();
	void output();
	string getNameClass();
	~NghienCuuVien();	
};

class ChuyenVien :public NhanSu
{
private:
	vector <string> maduan_CV;
	int sonamkinhnghiem;
public:
	ChuyenVien();
	ChuyenVien(string hoten, string ngaysinh, string masoNS, vector <string> maDA, int sonamKN);
	void setLuong();
	void input();
	void output();
	string getNameClass();
	~ChuyenVien();
};

class ThucTapSinh : public NhanSu
{
private:
	int tgThucTap;
	vector<string> maduan_dubi;
public:
	ThucTapSinh();
	ThucTapSinh(string hoten, string ngaysinh, string masoNS, int init_tgThucTap, vector <string> duan);
	void setLuong();
	void input();
	void output();
	string getNameClass();
	~ThucTapSinh();

};

class TruongHoc
{
private:
	vector<NhanSu*> dsNhanSu;
public:
	TruongHoc();
	TruongHoc(vector <NhanSu*>m_dsNhanSu);
	TruongHoc(const TruongHoc& mTruongHoc);
	void input();
	void output();
	float calcLuong();
	void highestLuong();
	~TruongHoc();
};
