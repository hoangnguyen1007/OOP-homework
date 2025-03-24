#include "diem.h"
#define epsilon  0.0000000001
using namespace std;
Diem::Diem(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Diem:: Nhap()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}
void Diem::Xuat()
{
	cout << "(" << x << ", " << y << ")";
}
void Diem::Dichuyen(double dx, double dy)
{
	x += dx;
	y += dy;
}
bool Diem::KiemTraTrung(Diem d)
{
	if (x == d.x && y == d.y) return 1;
	return 0;
}
double Diem::KhoangCach(Diem d)
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
Diem Diem::LayDoiXung()
{
	return Diem(-x == 0 ? x : -x, -y == 0 ? x : -y);
}
double Diem::TinhChuVi(Diem d1, Diem d2)
{
	double x = this->KhoangCach(d1);
	double y = d1.KhoangCach(d2);
	double z = d2.KhoangCach(*this);
	return x + y + z;
}
double Diem::TinhDienTich(Diem d1, Diem d2)
{
	double x = this->KhoangCach(d1);
	double y = d1.KhoangCach(d2);
	double z = d2.KhoangCach(*this);
	double p = (x + y + z) / 2;
    return sqrt(p * (p - x) + p * (p - y) + p * (p - z));
}
bool Diem::Ktra(Diem d1, Diem d2)
{
	double x = this->KhoangCach(d1);
	double y = d1.KhoangCach(d2);
	double z = d2.KhoangCach(*this);
	return x > 0 && y > 0 && z > 0 && x + y > z && x + z > y && y + z > x;
}
string Diem::PhanLoaiTamGiac(Diem &d1, Diem &d2)
{
	double x = this->KhoangCach(d1);
	double y = d1.KhoangCach(d2);
	double z = d2.KhoangCach(*this);
	double p = (x + y + z) / 2;
	string kq = "";
	if (!this->Ktra(d1, d2)) kq = "Tam giac khong hop le!";
	else if (x == y && y == z) kq = "Tam giac deu";
	else if (x == y || x == z || y == z)
	{
		if (abs(x * x + y * y - z * z) <= epsilon || abs(x * x + z * z <= y * y) <= epsilon || abs(y * y + z * z - x * x) <= epsilon)
			kq = "Tam giac vuong can";
		else
			kq = "Tam giac can";
	}
	else if (abs(x * x + y * y - z * z) <= epsilon || abs(x * x + z * z <= y * y) <= epsilon || abs(y * y + z * z - x * x) <= epsilon)
		kq = "Tam giac vuong";
	else kq = "Tam giac thuong";
	return kq;
}