#inculde<iostream>
#include<string>
using namespace std;

class Nhanvien{
  protected:
    string Hoten;
    int Manhanvien;
#include<string>
using namespace std;

class Nhanvien{
  protected:
    string Hoten;
    int Manhanvien;
    int Namsinh;
    string Quequan;
    int Sonamlamviec;
  public:
    Nhanvien(); 
    Nhanvien(string Ht, int Mnv, int Ns, string Que,int Snlv);
    Nhanvien(const Nhanvien &nv);
    ~Nhanvien();
    friend istream& operator >> (istream&is, Nhanvien &nv);
    int Namsinh;
    string Quequan;
    int Sonamlamviec;
  public:
    Nhanvien(); 
    Nhanvien(string Ht, int Mnv, int Ns, string Que,int Snlv);
    Nhanvien(const Nhanvien &nv);
    ~Nhanvien();
    friend istream& operator >> (istream&is, Nhanvien &nv);
    friend ostream& operator << (ostream&os, Nhanvien nv);
};
Nhanvien::Nhanvien(){
  Hoten="";
  Manhanvien="";
  Namsinh="";
  Quequan=""
  Sonamlamviec=0;
}
Nhanvien::Nhanvien(string Ht, int Mnv, int Ns, string Que,int Snlv){
  Hoten=Ht;
  Manhanvien=Mnv;
  Namsinh=Ns;
  Quequan=Que;
  Sonamlamviec=snlv;
}
Nhanvien::Nhanvien(const Nhanvien&nv){
  Hoten=nv.Hoten;
  Manhanvien=nv.Manhanvien;
  Namsinh=nv.Namsinh;
  Quequan=nv.Quequan;
  Sonamlamviec=nv.Sonamlamviec;
}
Nhanvien::~Nhanvien(){
}
istream& operator >> (istream&is, Nhanvien &nv){
  cout << "Nhap ho va ten: ";
  getline(cin, nv.Hoten);
  cout << "Nhap ma nhan vien: ";
  is>>nv.Manhanvien;
  cout<< "Nhap nam sinh: ";
  is>>nv.Namsinh;
  cout<< "Nhap que quan: ";
  getline(cin,nv.Quequan);
  cout<< "Nhap so nam lam viec: ";
  is>>nv.Sonamlamviec;
  return is;
}
ostream& operator << (ostream&os, Nhanvien nv){
  os<<"\nHo va ten: "<<nv.Hoten;
  os<<"\nMa nhan vien: "<<nv.Manhanvien;
  os<<"\nNam sinh: "<<nv.Namsinh;
  os<<"\Que quan: "<<nv.Quequan;
  os<<"\nSonamlamviec: "<<nv.Sonamlamviec;
  return os;
}

