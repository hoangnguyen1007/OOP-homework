#include "cTamGiac.h"
#include<iostream>
#include<cmath>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
using namespace std;
#define epsilon  1e-6
constexpr double PI = 3.14159265358979323846;
//Ham nhap diem va kiem tra du lieu dau vao
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
//Ham xuat thong tin diem duoc nhap
void Diem::Xuat() const
{
	cout << "(" << x << ", " << y << ")";
}
//Ham tinh va tra ve khoang cach tu diem this den diem d duoc truyen vao
double Diem::KhoangCach(Diem d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
//Ham nhan vao 2 gia tri dx dy de thay doi gia tri cua 1 diem
void Diem::DiChuyen(int dx, int dy)
{
	x += dx;
	y += dy;
}
//Ham getter tra ve gia tri cua toa do x
double Diem::getX() const
{
	return x;
}
//Ham getter tra ve gia tri cua toa do y
double Diem::getY() const
{
	return y;
}
//Ham setter dung de thay doi gia tri cua toa do x
void Diem::setX(double x)
{
	this->x = x;
}
//Ham setter dung de thay doi gia tri cua toa do y
void Diem::setY(double y)
{
	this->y = y;
}
//Ham construction khoi tao lop tam giac khong truyen vao tham so
cTamGiac::cTamGiac() {}
//Ham construction khoi tao lop tam giac co truyen vao tham so
cTamGiac::cTamGiac(Diem a, Diem b, Diem c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
//Nap chong toan tu nhap, nhap 3 diem cua 1 tam giac
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
//Nhap chong toan tu xuat, xuat lan luot 3 dinh cua tam giac
ostream& operator<<(ostream& os, cTamGiac x)
{
	os << "Diem A: "; x.a.Xuat(); cout << endl;
	os << "Diem B: "; x.b.Xuat(); cout << endl;
	os << "Diem C: "; x.c.Xuat();
	return os;
}
//Ham ve tam giac trong cua so 800x600, su dung thu vien graphics
//Ham tinh toan de hinh tam giac to hon, dua ve giua cua so
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
//Ham tinh toan do dai cac canh cua tam giac va kiem tra xem tam giac co hop le khong
bool cTamGiac::Ktra() const
{
	double x = a.KhoangCach(b);
	double y = b.KhoangCach(c);
	double z = a.KhoangCach(c);
	return x > 0 && y > 0 && z > 0 && x + y > z && x + z > y && y + z > x;
}
//Ham tinh toan do dai cac canh cua tam giac va tra ve chuoi ten loai tam giac
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
//Ham tinh toan do dai cac canh, tinh va tra ve chu vi tam giac
double cTamGiac::ChuVi() const
{
	double x = a.KhoangCach(b);
	double y = b.KhoangCach(c);
	double z = a.KhoangCach(c);
	return x + y + z;
}
//Ham tinh toan do dai cac canh, tinh va tra ve dien tich tam giac
double cTamGiac::DienTich() const
{
	double x = a.KhoangCach(b);
	double y = b.KhoangCach(c);
	double z = a.KhoangCach(c);
	double p = (x + y + z) / 2;
	return sqrt(p * (p - x) * (p - y) * (p - z));
}
//Ham nhan vao 1 vector va di chuyen toa do cac dinh tam giac theo vector ay
void cTamGiac::TinhTien(int x, int y)
{
	a.DiChuyen(x, y);
	b.DiChuyen(x, y);
	c.DiChuyen(x, y);
}
//Ham nhan vao tam quay va goc quay va tinh toan theo cong thuc quay tam giac
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
//Ham nhan vao tam vi tu, he so k, de phong to neu k > 1 va thu nho neu 0<k<1 theo cong thuc
void cTamGiac::PhongTo_ThuNho(double x, double y, double k)
{
	a.setX(k * (a.getX() - x) + x);
	a.setY(k * (a.getY() - y) + y);
	b.setX(k * (b.getX() - x) + x);
	b.setY(k * (b.getY() - y) + y);
	c.setX(k * (c.getX() - x) + x);
	c.setY(k * (c.getY() - y) + y);
}