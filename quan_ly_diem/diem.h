#pragma once
#include <iostream>
#include<string>
#include <math.h>
using namespace std;
class Diem
{
private:
	double x, y;
public:
	Diem(double = 0, double = 0);
	void Nhap();
	void Xuat();
	void Dichuyen(double dx, double dy);
	bool KiemTraTrung(Diem d);
	double KhoangCach(Diem d);
	Diem LayDoiXung();
	bool Ktra(Diem d1, Diem d2);
	double TinhChuVi(Diem d1, Diem d2);
	string PhanLoaiTamGiac(Diem& d1, Diem& d2);
	double TinhDienTich(Diem d1, Diem d2);
};