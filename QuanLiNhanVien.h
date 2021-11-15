#include <iostream>
#include<fstream>
#include<iomanip>
#include <windows.h>
#include<conio.h>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

struct Date {
    int ngay, thang, nam;
};

class NhanVien {
    private:
        string MaNV;
        string HoTen;
        string NoiSinh;
        Date NgaySinh;
        long LuongCoBan;
    public:
        NhanVien();
        ~NhanVien();
        virtual void doc_File(ifstream& filein);
        virtual void Nhap();
        virtual void Xuat();
        virtual long TinhLuong() = 0;
        long getLuong();
        string getMaNV();
        string getTen();
        string getNoiSinh();
        int getNamSinh();
        long getLuongCoBan();
        virtual void xuat_File(ofstream& fileout);
};

class NhanVienSanXuat : public NhanVien {
    private:
        float GiaMotSP;
        int SoSP;
    public:
        NhanVienSanXuat();
        ~NhanVienSanXuat();
        void doc_File(ifstream& filein);
        void Nhap();
        void Xuat();
       	long TinhLuong();
        void xuat_File(ofstream& fileout);
};

class NhanVienVanPhong : public NhanVien {
     private:
        float HeSoLuong;
        int SoNgayLam;
     public:
        NhanVienVanPhong();
        ~NhanVienVanPhong();
        void doc_File(ifstream& filein);
        void Nhap();
        void Xuat();
        long TinhLuong();
        void xuat_File(ofstream& fileout);
};

class QuanLyNhanVien {
	private:
		NhanVien *nv[1000];
		int n;
	public:
		void doc_File(ifstream& filein);
		void Xuat_DS_NVSX();
        void Xuat_DS_NVVP();
		void ThemNV();
		void XoaNV();
		void SapXep();
		void TimKiem();
        void xuat_File(ofstream& fileout);
};


struct Menu {
    Menu();
    int phimDiChuyen();
};