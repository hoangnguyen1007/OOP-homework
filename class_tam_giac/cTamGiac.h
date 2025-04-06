#pragma once
#include<iostream>
using namespace std;
class Diem
{
private:
	double x, y;
public:
	void Nhap();
	double KhoangCach(Diem d) const;
	void DiChuyen(int dx, int dy);
	void Xuat() const;
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
};
class cTamGiac
{
private:
	Diem a, b, c;
public:
	cTamGiac();
	cTamGiac(Diem a, Diem b, Diem c);
	friend istream& operator>>(istream& is, cTamGiac& x);
	friend ostream& operator<<(ostream& os, cTamGiac x);
	bool Ktra() const;
	string PhanLoaiTamGiac() const;
	double ChuVi() const;
	double DienTich() const;
	void TinhTien(int x, int y);
	void Quay(int x, int y, int p);
	void PhongTo_ThuNho(double x, double y, double k);
	void ve_tam_giac();
};

