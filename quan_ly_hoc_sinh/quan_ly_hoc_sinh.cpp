#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Lop quan ly thong tin hoc sinh
class HocSinh
{
private:
	string ten;
	double toan, van, anh;
public:
	//Nap chong toan tu nhap, kiem tra cac dieu kien nhap
	friend istream& operator>>(istream& is, HocSinh &x)
	{
		cout << "-----------------------------"<<endl;
		cout << "Nhap ten hoc sinh: ";
		cin.ignore();
		getline(is, x.ten);
		while (!x.Ktra_ten())
		{
			cout << "Vui long nhap lai ten hoc sinh: ";
			cin.ignore();
			getline(is, x.ten);
		}
		cout << "Nhap diem toan: ";
		is >> x.toan;
		while (cin.fail() || x.toan < 0 || x.toan > 10)
		{
			cin.clear();
			cin.ignore();
			cout << "Vui long nhap lai!" << endl;
			cout << "Nhap diem toan: ";
			is >> x.toan;
		}
		cout << "Nhap diem van: ";
		is >> x.van;
		while (cin.fail() || x.van < 0 || x.van > 10)
		{
			cin.clear();
			cin.ignore();
			cout << "Vui long nhap lai!" << endl;
			cout << "Nhap diem van: ";
			is >> x.van;
		}
		cout << "Nhap diem ngoai ngu: ";
		is >> x.anh;
		while (cin.fail() || x.anh < 0 || x.anh > 10)
		{
			cin.clear();
			cin.ignore();
			cout << "Vui long nhap lai!" << endl;
			cout << "Nhap diem ngoai ngu: ";
			is >> x.anh;
		}
		return is;
	}
	//Nap chong toan tu xuat
	friend ostream& operator<<(ostream& os, HocSinh x)
	{
		os << "Ho va ten: " << x.ten<<endl;
		os << "Diem trung binh: " << x.dtb()<<endl;
		os << x.phan_loai()<<endl;
		return os;
	}
	double dtb();
	string getTen();
	double getToan();
	double getVan();
	double getAnh();
	string phan_loai();
	bool Ktra_ten();
};
//Ham kiem tra trong chuoi ten co ki tu so khong
bool HocSinh::Ktra_ten()
{
	for (int i = 0; i < ten.length(); i++)
	{
		if (isdigit(ten[i])) return 0;
	}
	return 1;
}
//Cac ham get lay thong tin hoc sinh
string HocSinh::getTen()
{
	return ten;
}
double HocSinh::getToan()
{
	return this->toan;
}
double HocSinh::getVan()
{
	return this->van;
}
double HocSinh::getAnh()
{
	return this->anh;
}
//Ham phan loai dua vao dtb de phan loai hoc sinh, tra ve chuoi phan loai
string HocSinh::phan_loai()
{
	string kq = "";
	if (this->dtb() >= 9) kq = "Hoc sinh xuat sac";
	else if (this->dtb() >= 8) kq = "Hoc sinh gioi";
	else if (this->dtb() >= 6.5) kq = "Hoc Sinh kha";
	else if (this->dtb() >= 5) kq = "Hoc sinh trung binh";
	else kq = "Hoc sinh yeu";
	return kq;
}
//Ham nhan vao 3 diem thanh phan cua hoc sinh va tinh diem trung binh
double HocSinh::dtb()
{
	return (2 * toan + van + anh) / 4;
}
//Ham nhan vao mot mang a, tra ve hoc sinh co dtb cao nhat
HocSinh dtb_max(vector<HocSinh> a, int n)
{
	double max_dtb = a[0].dtb();
	int max_i = 0;
	for (int i = 0; i < n; i++)
	{
		if (max_dtb < a[i].dtb())
		{
			max_dtb = a[i].dtb();
			max_i = i;
		}
	}
	return a[max_i];
}
//Ham viet thuong tat ca cac ki tu trong chuoi
string to_lowers(string s)
{
	string t = s;
	for (int i = 0; i < s.size(); i++)
	{
		t[i] = tolower(s[i]);
	}
	return t;
}
//Ham tim kiem hoc sinh dua vao tu khoa cua nguoi dung
vector<HocSinh> tim_kiem(vector<HocSinh> x)
{
	vector<HocSinh> res;
	cout << "Nhap tu khoa ten hoc sinh ban muon tim: ";
	string t;
	cin.ignore();
	getline(cin, t);
	t = to_lowers(t);
	for (auto i : x)
	{
		string s;
		s = to_lowers(i.getTen());
		if (s.find(t) != string::npos)
		{
			res.push_back(i);
		}
	}
	return res;
}
//Ham so sanh de so sanh diem toan tang dan cho ham sort
bool cmp(HocSinh a, HocSinh b)
{
	return a.getToan() < b.getToan();
}
int main()
{
	int n;
	int c;
	cout << "Nhap so hoc sinh: ";
	cin >> n;
	vector<HocSinh> a(n);
	vector<HocSinh> tmp;
	vector<HocSinh> tmp1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	do
	{
		cout << "=============CHUONG TRINH QUAN LY HOC SINH===============" << endl;
		cout << "1.Xuat danh sach hoc sinh" << endl;
		cout << "2.Xuat hoc sinh co diem trung binh cao nhat" << endl;
		cout << "3.Tim kiem hoc sinh theo ten" << endl;
		cout << "4.Danh sach hoc sinh duoc sap xep theo diem toan tang dan" << endl;
		cout << "0. Thoat chuong trinh!" << endl;
		cout << "=========================================================" << endl;
		cout << "Lua chon cua ban la: ";
		int choose;
		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				cout << "--------Hoc sinh thu " << i + 1 << "---------- " << endl;
				cout << a[i];
			}
			break;
		case 2:
			cout << "Hoc sinh co diem trung binh cao nhat la: " << endl;
			cout << dtb_max(a, n);
			break;

		case 3:
			tmp = tim_kiem(a);
			if (tmp.size() == 0)
			{
				cout << "Khong tim thay hoc sinh nao!"<<endl;
			}
			else
			{
				cout << "---------Ket qua tim kiem-----------" << endl;
				for (auto i : tmp)
				{
					cout << i;
					cout << "---------------------------------" << endl;
				}
			}
			break;
		case 4:
			tmp1 = a;
			sort(tmp1.begin(), tmp1.end(), cmp);
			for (int i = 0; i < tmp1.size(); i++)
			{
				cout << "---------Hoc Sinh " << i + 1 << "------------" << endl;
				cout << tmp1[i];
			}
			break;
		case 0:
			cout << "Dang thoat chuong trinh!.....";
			return 0;
		default:
			cout << "Khong hop le!"<<endl;
		}
		cout << "-----------------------------------------" << endl;
		cout << "Ban co muon tiep thuc khong? " << endl;
		cout << "1.Co" << endl;
		cout << "0.Khong" << endl;
		cin >> c;
	} while (c != 0);
	cout << "Dang thoat chuong trinh!....";
	return 0;
}
