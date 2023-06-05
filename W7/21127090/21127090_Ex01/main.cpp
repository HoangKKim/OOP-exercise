#include "NhanSu.h"
#include <iomanip>

int main()
{
	TruongHoc HCMUS;
	HCMUS.input();
	cout << endl;
	HCMUS.output();
	cout << "Tien luong: " << fixed << setprecision(2) << HCMUS.calcLuong();
	HCMUS.~TruongHoc();
}