#include <iostream>
#include <iomanip>
using namespace std;

struct Ngay {
    unsigned int ngay;
    unsigned int thang;
    unsigned int nam;
};

class NhanVien {
    private:
        string Ten;
        string Ma;
        string NoiSinh;
        Ngay NgaySinh;
        float LuongCoBan;
    public:
        NhanVien();
        ~NhanVien();
        virtual void Nhap();
        virtual void Xuat();
        virtual float TinhLuong() = 0;
        virtual float getLuong();
};


