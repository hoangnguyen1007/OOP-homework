#include "cTamGiac.h"
#include<iostream>
#include<cmath>
#include "graphics.h"

#pragma comment(lib, "graphics.lib")
using namespace std;
#define epsilon  1e-6
constexpr double PI = 3.14159265358979323846;
void Diem::Nhap()
{
	cin >> x;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cin >> x;
	}
    cin >> y;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cin >> y;
	}
}
void Diem::Xuat() const
{
	cout << "(" << x << ", " << y << ")";
}
double Diem::KhoangCach(Diem d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
void Diem::DiChuyen(int dx, int dy)
{
	x += dx;
	y += dy;
}
double Diem::getX() const
{
	return x;
}
double Diem::getY() const
{
	return y;
}
void Diem::setX(double x)
{
	this->x = x;
}
void Diem::setY(double y)
{
	this->y = y;
}
cTamGiac::cTamGiac() {}
cTamGiac::cTamGiac(Diem a, Diem b, Diem c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
istream& operator>>(istream& is, cTamGiac& x)
{
	cout << "Nhap 3 diem cua tam giac: "<<endl;
	cout << "Nhap diem A: ";
	x.a.Nhap();
	cout << "Nhap diem B: ";
	x.b.Nhap();
	cout << "Nhap diem C: ";
	x.c.Nhap();
	return is;
}
ostream& operator<<(ostream& os, cTamGiac x)
{
	os << "Diem A: "; x.a.Xuat(); cout << endl;
	os << "Diem B: "; x.b.Xuat(); cout << endl;
	os << "Diem C: "; x.c.Xuat();
	return os;
}
void cTamGiac::ve_tam_giac()
{
	initwindow(800, 600);
	int offsetX = 800 / 2; 
	int offsetY = 600 / 2;
	line(a.getX() * 10 + offsetX, -a.getY() * 10 + offsetY,
		b.getX() * 10 + offsetX, -b.getY() * 10 + offsetY);
	line(b.getX() * 10 + offsetX, -b.getY() * 10 + offsetY,
		c.getX() * 10 + offsetX, -c.getY() * 10 + offsetY);
	line(c.getX() * 10 + offsetX, -c.getY() * 10 + offsetY,
		a.getX() * 10 + offsetX, -a.getY() * 10 + offsetY);
}
bool cTamGiac::Ktra() const
{
	double x = a.KhoangCach(b);
	double y = b.KhoangCach(c);
	double z = a.KhoangCach(c);
	return x > 0 && y > 0 && z > 0 && x + y > z && x + z > y && y + z > x;
}
string cTamGiac::PhanLoaiTamGiac() const
{
	double x = a.KhoangCach(b);
	double y = b.KhoangCach(c);
	double z = a.KhoangCach(c);
	string kq = "";
	if (!Ktra())
		kq = "tam giac khong hop le!";
	else if (fabs(x - y) <= epsilon && fabs(x - z) <= epsilon)
		kq = "tam giac deu";
	else if (fabs(x - y) <= epsilon || fabs(y - z) <= epsilon || fabs(x - z) <= epsilon)
	{
		if (fabs(x * x + y * y - z * z) <= epsilon ||
			fabs(x * x + z * z - y * y) <= epsilon ||
			fabs(y * y + z * z - x * x) <= epsilon)
			kq = "tam giac vuong can";
		else
			kq = "tam giac can";
	}
	else if (fabs(x * x + y * y - z * z) <= epsilon ||
		fabs(x * x + z * z - y * y) <= epsilon ||
		fabs(y * y + z * z - x * x) <= epsilon)
		kq = "tam giac vuong";
	else
		kq = "tam giac thuong";

	return kq;
}
double cTamGiac::ChuVi() const
{
	double x = a.KhoangCach(b);
	double y = b.KhoangCach(c);
	double z = a.KhoangCach(c);
	return x + y + z;
}
double cTamGiac::DienTich() const
{
	double x = a.KhoangCach(b);
	double y = b.KhoangCach(c);
	double z = a.KhoangCach(c);
	double p = (x + y + z) / 2;
	return sqrt(p * (p - x) * (p - y) * (p - z));
}
void cTamGiac::TinhTien(int x, int y)
{
	a.DiChuyen(x, y);
	b.DiChuyen(x, y);
	c.DiChuyen(x, y);
}
void cTamGiac::Quay(int x, int y, int p)
{	
	double phi = p * PI / 180;
	Diem t1, t2, t3;
	t1.setX((a.getX() - x) * cos(phi) - (a.getY() - y) * sin(phi) + x);
	t1.setY((a.getX() - x) * sin(phi) + (a.getY() - y) * cos(phi) + y);
	t2.setX((b.getX() - x) * cos(phi) - (b.getY() - y) * sin(phi) + x);
	t2.setY((b.getX() - x) * sin(phi) + (b.getY() - y) * cos(phi) + y);
	t3.setX((c.getX() - x) * cos(phi) - (c.getY() - y) * sin(phi) + x);
	t3.setY((c.getX() - x) * sin(phi) + (c.getY() - y) * cos(phi) + y);
	a.setX(t1.getX()); a.setY(t1.getY());
	b.setX(t2.getX()); b.setY(t2.getY());
	c.setX(t3.getX()); c.setY(t3.getY());
}
void cTamGiac::PhongTo_ThuNho(double x, double y, double k)
{
	a.setX(k * (a.getX() - x) + x);
	a.setY(k * (a.getY() - y) + y);
	b.setX(k * (b.getX() - x) + x);
	b.setY(k * (b.getY() - y) + y);
	c.setX(k * (c.getX() - x) + x);
	c.setY(k * (c.getY() - y) + y);
}