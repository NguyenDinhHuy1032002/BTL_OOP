#include "NhanVien.hpp"
using namespace std;

NhanVien::NhanVien() {
    Ten = "";
    Ma = "";
    NoiSinh = "";
    NgaySinh.ngay = 0;
    NgaySinh.thang = 0;
    NgaySinh.nam = 0;
    LuongCoBan = 0;
}
NhanVien::~NhanVien(){}

void NhanVien::Nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, Ten);
    cout << "Nhap ma nhan vien: ";
    getline(cin , Ma);
    cout << "Nhap noi sinh: ";
    getline(cin, NoiSinh);
    cout << "Nhap ngay sinh: ";
    cin >> NgaySinh.ngay >> NgaySinh.thang >> NgaySinh.nam;
    cout << "Nhap luong co ban: ";
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << Ten << endl;
    cout << "Ma nhan vien: " << Ma << endl;
    cout << "Noi sinh: " << endl;
    cout << "Ngay sinh: " << NgaySinh.ngay << "/" << NgaySinh.thang << "/" << NgaySinh.nam << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
}

float NhanVien::getLuong() {
    return this->TinhLuong();
}
