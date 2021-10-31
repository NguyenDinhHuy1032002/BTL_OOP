#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Date {
    int ngay, thang, nam;
};

void Doc_Ngay(ifstream& filein, Date &NgaySinh) {
    filein >> NgaySinh.ngay;
    filein.ignore();
    filein >> NgaySinh.thang;
    filein.ignore();
    filein >> NgaySinh.nam;
    filein.ignore();
}

class NhanVien {
    private:
        string Ma;
        string HoTen;
        Date NgaySinh;
        long LuongCoBan;
    public:
        virtual void Doc_File(ifstream& filein);
        virtual void Xuat();
        virtual long TinhLuong() = 0;
        long getLuong();
        long getLuongCoBan();
};

class NhanVienSanXuat : public NhanVien {
    private:
        float GiaMotSP;
        int SoSP;
    public:
        void Doc_File(ifstream& filein);
        void Xuat();
        long TinhLuong();
};

class NhanVienVanPhong : public NhanVien {
    private:
        float HeSoLuong;
        int SoNgayLam;
    public:
        void Doc_File(ifstream& filein);
        void Xuat();
        long TinhLuong();
};