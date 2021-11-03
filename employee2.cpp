#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

//khaibaolopcha: NhanVien
class NhanVien
{
 protected:
     string HoTen;
     string MaNhanVien;
     int Namsinh;
     string DiaChi;
     long LuongCoBan;
  public:
     NhanVien();
     ~NhanVien();
     long getLuong();
     long getLuongCoBan();
     virtual void DocFile(ifstream& filein);
     virtual void Xuat();
     virtual long TinhLuong() = 0;
};

//Khai bao lop con Nhan Vien san xuat ke thua lop cha 
class NhanVienSanXuat:public NhanVien 
{
  private: 
     float GiamotSP;
     int SoSP;
  public:
     NhanVienSanXuat();
     ~NhanVienSanXuat();
     void DocFile(ifstream& filein);
     void Xuat();
     long TinhLuong();
};

//Khai bao lop con Nhan vien van phong ke thua lop cha
class NhanVienVanPhong:public NhanVien
{
   private: 
     float HeSoLuong;
     int SoNgayLam;
   public:
     NhanVienVanPhong();
     ~NhanVienVanPhong();
     void DocFile(ifstream& filein);
     void Xuat();
     long TinhLuong();
};

//Khai bao quan ly nhan vien 
//Tat ca nhan vien se duoc luu trong 1 mang duy nhat la dsNV
//Moi nhan vien trong dsNV se la 1 con tro de tro toi nhan vien
class QuanLyNhanVien
{
   private:
      vector<NhanVien *> dsNV; 
   public:
      void Docfile(ifstream& filein);
      void Xuat();
      long TinhLuong();
      void SapXep();
      void ThemNhanVien();
      void XoaNhanvien();
      void Timkiem();
};

//NHAN VIEN 
NhanVien::NhanVien()
{
    HoTen = "";
    MaNhanVien = "";
    Namsinh = 0;
    DiaChi = "";
    LuongCoBan = 0;
}

NhanVien::~NhanVien(){}

long NhanVien::getLuong()
{
    return this->TinhLuong();
}

long NhanVien::getLuongCoBan()
{
    return this->LuongCoBan;
}

void NhanVien::DocFile(ifstream& filein)
{
    getline(filein, HoTen, ','); //Doc den dau phay thi dung
    filein.ignore();
    getline(filein, MaNhanVien, ',');
    filein.ignore();
    filein >> Namsinh;
    filein.ignore();
    getline(filein, DiaChi, ',');
    filein.ignore();
    filein >> LuongCoBan;
}

void NhanVien::Xuat()
{
    cout<<"\n Ho ten Nhan vien: "<<HoTen;
    cout<<"\n Ma Nhan vien: "<<MaNhanVien;
    cout<<"\n Nam sinh: "<<Namsinh;
    cout<<"\n Dia chi: "<<DiaChi;
    cout<<"\n Luong co ban: "<<LuongCoBan;
}

//NHAN VIEN SAN XUAT
NhanVienSanXuat::NhanVienSanXuat()
{
    GiamotSP = 0;
    SoSP = 0;
}

NhanVienSanXuat::~NhanVienSanXuat(){}

void NhanVienSanXuat::DocFile(ifstream& filein)
{
     NhanVien::DocFile(filein);
     filein>>GiamotSP;
     filein.ignore();
     filein>>SoSP;
     filein.ignore();
}

void NhanVienSanXuat::Xuat()
{
    cout<<"\nGia mot san pham la: "<<GiamotSP;
    cout<<"\nso san pham la: "<<SoSP;
}

long NhanVienSanXuat::TinhLuong()
{
    long Luong = 0;
    Luong = this->getLuongCoBan() + GiamotSP*SoSP;
    return Luong;
}

//NHANVIENVANPHONG

NhanVienVanPhong::NhanVienVanPhong()
{
    HeSoLuong = 0;
    SoNgayLam = 0;
}
 
NhanVienVanPhong::~NhanVienVanPhong(){}

void NhanVienVanPhong::DocFile(ifstream& filein) {
    NhanVien::DocFile(filein);
    filein >> HeSoLuong;
    filein.ignore();
    filein >> SoNgayLam;
    filein.ignore();
}

void NhanVienVanPhong::Xuat()
{
    cout<<"\nHe so luong la: "<<HeSoLuong;
    cout<<"\nSo ngay lam la: "<<SoNgayLam;
}

//QUAN LI NHAN VIEN 

