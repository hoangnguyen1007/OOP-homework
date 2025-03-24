#include "diem.h"
using namespace std;
int main()
{
    Diem d1 = { 0, 0 }, d2 = { 0, 0 }, d3 = {0, 0};
    int chon;
    int c;
    Diem res;
    do
    {
        cout << "--------------CHUONG TRINH----------------" << endl;
        cout << "1.Nhap vao toa do 3 diem" << endl;
        cout << "2.Xuat toa do 3 diem" << endl;
        cout << "3.Di chuyen mot diem" << endl;
        cout << "4.Kiem tra toa do co trung khong" << endl;
        cout << "5.Tinh khoang cach giua hai diem" << endl;
        cout << "6.Lay diem doi xung qua goc toa do" << endl;
        cout << "7.Tinh chu vi tam giac" << endl;
        cout << "8.Tinh dien tich tam giac" << endl;
        cout << "9.Phan loai tam giac" << endl;
        cout << "0.Thoat chuong trinh" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Lua chon cua ban la: ";
        cin >> chon;
        system("cls");
        switch (chon)
        {
        case 1:
            cout << "Nhap toa do diem thu nhat: "<<endl;
            d1.Nhap();
            cout << "Nhap toa do diem thu hai: "<<endl;
            d2.Nhap();
            cout << "Nhap toa do diem thu ba: "<<endl;
            d3.Nhap();
            break;
        case 2:
            cout << "\nToa do diem thu nhat: ";
            d1.Xuat();
            cout << "\nToa do diem thu hai: ";
            d2.Xuat();
            cout << "\nToa do diem thu ba: ";
            d3.Xuat();
            break;
        case 3:
            cout << "Ban muon di chuyen diem nao ?: " << endl;
            cout << "1.Diem thu nhat" << endl;
            cout << "2.Diem thu hai" << endl;
            cout << "3.Diem thu ba" << endl;
            int choose;
            cin >> choose;
            cout << "Di chuyen x: ";
            int x; cin >> x;
            cout << "Di chuyen y: ";
            int y; cin >> y;
            if (choose == 1)  d1.Dichuyen(x, y);
            else if (choose == 2) d2.Dichuyen(x, y);
            else d3.Dichuyen(x, y);
            cout << "Da di chuyen thanh cong!";
            break;
        case 4:
            if (d1.KiemTraTrung(d2) && d2.KiemTraTrung(d3)) cout << "3 diem deu trung nhau";
            else if (d1.KiemTraTrung(d2)) cout << "Diem thu nhat trung diem thu hai";
            else if (d1.KiemTraTrung(d3)) cout << "Diem thu nhat trung diem thu ba";
            else if (d2.KiemTraTrung(d3)) cout << "Diem thu hai trung diem thu ba";
            else cout << "Ba diem khong trung!";
            break;
        case 5:
            cout << "Khoang cach tu diem thu 1 den diem thu 2 la: " << d1.KhoangCach(d2) << endl;
            cout << "Khoang cach tu diem thu 2 den diem thu 3 la: " << d2.KhoangCach(d3) << endl;
            cout << "Khoang cach tu diem thu 1 den diem thu 3 la: " << d1.KhoangCach(d3) << endl;
            break;
        case 6:
            cout << "Ban muon lay diem nao doi xung qua goc toa do ?" << endl;
            cout << "1.Diem thu nhat" << endl;
            cout << "2.Diem thu hai" << endl;
            cout << "3.Diem thu ba" << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                res = d1.LayDoiXung();
                cout << "Diem doi xung la: "; res.Xuat();
            }
            else if (ch == 2)
            {
                res = d2.LayDoiXung();
                cout << "Diem doi xung la: "; res.Xuat();
            }
            else
            {
                res = d3.LayDoiXung();
                cout << "Diem doi xung la: "; res.Xuat();
            }
            break;
        case 7:
            if (d1.Ktra(d2, d3)) cout << "Chu vi cua tam giac la: " << d1.TinhChuVi(d2, d3);
            else cout << "Tam giac khong hop le!";
            break;
        case 8:
            if (d1.Ktra(d2, d3)) cout << "Dien tich cua tam giac la: " << d1.TinhDienTich(d2, d3);
            else cout << "Tam giac khong hop le!";
            break;
        case 9:
            cout<<"Tam giac nay la: "<<d1.PhanLoaiTamGiac(d2, d3);
            break;
        case 0:
            cout << "Dang thoat chuong trinh!.......";
            return 0;
        default:
            cout << "Lua chon khong hop le!";
        }
        cout << "\nBan co muon tiep tuc khong" << endl;
        cout << "1.CO"<<endl;
        cout << "0.KHONG"<<endl;
        cin >> c;
        system("cls");
    } while (chon != 0 && c != 0);
    cout << "Dang thoat chuong trinh!.......";
}
