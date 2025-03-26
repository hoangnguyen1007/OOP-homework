#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class chuyen_bay
{
private:
    string ma, noi_di, noi_den;
    int ngay, thang, nam;
	string gio_bay;
public:
	void Nhap();
	void Xuat();
	int getNam();
	int getThang();
	int getNgay();
	string getMa();
	string getNoiDi();
	string getNoiDen();
	string getGioBay();
	int SoNgayTrongThang(int thang,int nam);
};
//Cac ham getor lay gia tri cua cac thanh phan trong private
string chuyen_bay::getGioBay()
{
	return gio_bay;
}
int chuyen_bay::getNam()
{
	return nam;
}
int chuyen_bay::getThang()
{
	return thang;
}
int chuyen_bay::getNgay()
{
	return ngay;
}

string chuyen_bay::getMa()
{
	return ma;
}
string chuyen_bay::getNoiDi()
{
	return noi_di;
}
string chuyen_bay::getNoiDen()
{
	return noi_den;
}
//Ham xuat thong tin chuyen bay
void chuyen_bay::Xuat()
{
	cout << "Ma chuyen bay: " << ma<<endl;
	cout << "Ngay bay: ";
	if (ngay < 10) cout<< 0;
	cout << ngay << "/";
	if (thang < 10) cout << 0;
	cout << thang << "/" << nam;
	cout << endl;
	cout << "Gio bay: " << gio_bay<<endl;
	cout << "Noi di: " << noi_di<<endl;
	cout << "Noi den: " << noi_den<<endl;
}
//Ham kieu tra trong chuoi co so khong
bool check_so_trong_chuoi(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i])) return 1;
	}
	return 0;
}
//Ham kieu tra trong chuoi co ki tu dac biet khong
bool check_ki_tu_dac_biet(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') continue;
		if (!isdigit(s[i]) && !isalpha(s[i])) return 1;
	}
	return 0;
}
//Ham check trong chuoi co khoang trang khong
bool check_khoang_trang(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') return 1;
	}
	return 0;
}
//Nhan vao nam va xac dinh xem nam do co phai nam nhuan khong
bool NamNhuan(int nam)
{
	if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) return 1;
	return 0;
}
//Ham nhan vao thang va nam de tra ve so ngay trong thang nam do
int chuyen_bay::SoNgayTrongThang(int thang, int nam)
{
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (NamNhuan(nam)) return 29;
		else return 28;
		break;
	default:
		return -1;
	}
}
//Ham nhap va kiem tra cac dieu kien nhap
void chuyen_bay::Nhap()
{
	cout << "Nhap ma chuyen bay: ";
	cin >> ma;
	while (ma.length() > 5 || check_khoang_trang(ma) || check_ki_tu_dac_biet(ma))
	{
		cout << "Vui long nhap lai ma chuyen bay!" << endl;
		cout << "Nhap ma chuyen bay: ";
		cin >> ma;
	}
	cout << "Nhap ngay thang nam: ";
	cin >> ngay >> thang >> nam;
	while (cin.fail() || ngay < 0 || ngay > 31 || thang < 0 || thang > 12 || nam < 0 || ngay > SoNgayTrongThang(thang, nam))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Vui long nhap lai!" << endl;
		cout << "Nhap ngay thang nam: ";
		cin >> ngay >> thang >> nam;
	}
	cout << "Nhap gio bay:";
	cin >> gio_bay;
	cout << "Nhap noi di: ";
	cin.ignore();
	getline(cin, noi_di);
	while (noi_di.length() > 20 || check_ki_tu_dac_biet(noi_di) || check_so_trong_chuoi(noi_di))
	{
		cout << "Vui long nhap lai noi di!" << endl;
		cout << "Nhap noi di: ";
		cin.ignore();
		getline(cin, noi_di);
	}
	cout << "Nhap noi den: ";
	getline(cin, noi_den);
	while (noi_den.length() > 20 || check_ki_tu_dac_biet(noi_den) || check_so_trong_chuoi(noi_den))
	{
		cout << "Vui long nhap lai noi den!" << endl;
		cout << "Nhap noi den: ";
		cin.ignore();
		getline(cin, noi_den);
	}
}
//Ham viet thuong tat ca ki tu trong chuoi
string to_lower(string s)
{
	string t = s;
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i] != ' ')
		t[i] = tolower(s[i]);
	}
	return t;
}
//Ham tim kiem nhan vao mot vector tra ve vector cac ket qua tim kiem
vector<chuyen_bay> tim_kiem(vector<chuyen_bay> x)
{
	cout << "Nhap tu khoa ban muon tim kiem: ";
	vector<chuyen_bay> res;
	string s;
	cin.ignore();
	getline(cin, s);
	string t = to_lower(s);
	for (auto i : x)
	{
		string s1 = to_lower(i.getMa());
		string s2 = to_lower(i.getNoiDi());
		string s3 = to_lower(i.getNoiDen());
		if (s1.find(t) != string::npos || s2.find(t) != string::npos || s3.find(t) != string::npos)
		{
			res.push_back(i);
		}
	}
	return res;
}
//Ham lay thoi gian tach tu chuoi thoi gian thanh 1 cap so chi gio va phut
pair<int, int> Lay_Tg(chuyen_bay s)
{
	string t = s.getGioBay();
	pair<int, int> kq;
	if (t.length() == 4) 
	{
		kq.first = t[0] - '0';
		kq.second = stoi(t.substr(2, 2)); 
	}
	else 
	{
		kq.first = stoi(t.substr(0, 2)); 
		kq.second = stoi(t.substr(3, 2));
	}
	return kq;
}
//Ham so sanh cac gia tri thoi gian de lam dieu kien cho ham sort
bool cmp(chuyen_bay a, chuyen_bay b)
{
	if (a.getNam() != b.getNam()) return a.getNam() < b.getNam();
	if (a.getThang() != b.getThang()) return a.getThang() < b.getThang();
	if (a.getNgay() != b.getNgay()) return a.getNgay() < b.getNgay();
	pair <int, int> tg1 = Lay_Tg(a);
	pair <int, int> tg2 = Lay_Tg(b);
	if (tg1.first != tg2.first) return tg1.first < tg2.first;
	return tg1.second < tg2.second;
}
//Ham liet ke tra ve vector cac thong tin chuyen bay co noi di va ngay di nhu dau vao
vector<chuyen_bay> liet_ke(vector<chuyen_bay> x)
{
	int ngay, thang, nam;
	string s;
	vector<chuyen_bay> kq;
	cout << "Nhap noi di: ";
	cin.ignore();
	getline(cin, s);
	cout << "Nhap ngay di: ";
	cin >> ngay >> thang >> nam;
	for (auto i : x)
	{
		if (s == i.getNoiDi() && ngay == i.getNgay() && i.getThang() == thang && nam == i.getNam())
		{
			kq.push_back(i);
		}
	}
	return kq;
}
//Ham dem chuyen bay duoc nhap vao
int dem_chuyen_bay(vector<chuyen_bay> x, string s, string s1)
{
	int dem = 0;
	for (auto i : x)
	{
		if (s == i.getNoiDi() && s1 == i.getNoiDen())dem++;
	}
	return dem;
}
int main()
{
	cout << "Nhap so chuyen bay: ";
	int n; cin >> n;
	if (n == 0)
	{
		cout << "Khong co chuyen bay nao!";
		return 0;
	}
    vector<chuyen_bay> p(n);
	vector<chuyen_bay> t;
	vector<chuyen_bay> t1;
	string s;
	string s1;
	int c;
	int res;
	cout << "Nhap thong tin cac chuyen bay:" << endl;
	for (int i = 0; i < n; i++)
	{
		p[i].Nhap();
	}
	sort(p.begin(), p.end(), cmp);
	do
	{
		cout << "==================CHUONG TRINH====================" << endl;
		cout << "1.Xuat danh sach thong tin cac chuyen bay" << endl;
		cout << "2.Tim kiem chuyen bay" << endl;
		cout << "3.Liet ke danh sach chuyen bay tu noi di trong thoi gian cu the" << endl;
		cout << "4.So chuyen bay tu diem di den diem toi" << endl;
		cout << "0.Thoat chuong trinh" << endl;
		cout << "Lua chon cua ban la: ";
		int choose;
		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1:
			cout << "--------Danh sach cac chuyen bay da duoc sap xep-------" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "-----------Chuyen bay thu " << i + 1 << "-------------" << endl;
				p[i].Xuat();
			}
			break;
		case 2:
			t = tim_kiem(p);
			if (t.size() != 0)
			{
				cout << "---------Ket qua tim kiem----------" << endl;
				for (auto i : t)
				{
					i.Xuat();
					cout << "------------------------------" << endl;
				}
			}
			else
			{
				cout << "Khong tim thay thong tin chuyen bay!" << endl;
			}
			break;
		case 3:
			t1 = liet_ke(p);
			if (t1.size() == 0)
			{
				cout << "Khong tim thay thong tin chuyen bay!" << endl;
				break;
			}
			else
			{
				cout << "---------Ket qua tim kiem----------" << endl;
				for (auto i : t1)
				{
					i.Xuat();
					cout << "------------------------------" << endl;
				}			
			}
			break;
		case 4:
			cout << "Nhap noi di: ";
			cin.ignore();
			getline(cin, s);
			cout << "Nhap diem den: " << endl;
			getline(cin, s1);
			res = dem_chuyen_bay(p, s, s1);
			cout << "So chuyen bay tim thay la: " << res << endl;
			break;
		case 0:
			cout << "Dang thoat chuong trinh!......";
			return 0;
		default:
			cout << "Cu phap khong hop le!" << endl;
		}
		cout << "-----------------------------" << endl;
		cout << "Ban co muon tiep tuc khong?" << endl;
		cout << "1.Co" << endl;
		cout << "0.Khong" << endl;
		cin >> c;
		system("cls");
	} while (c != 0);
}