#include "NhanVien.hpp"
using namespace std;

// Ngay
// phuong thuc getter cua ngay
int Ngay::Getter_Ngay(){
    return ngay;
}
// phuong thuc setter cua ngay
void Ngay::Setter_Ngay(int NGAY) {
    ngay =  NGAY;
}
// phuong thuc getter cua thang
int Ngay::Getter_Thang() {
	return thang
}
// phuong thuc setter cua thang
void Ngay::Setter_Thang(int THANG) {
	thang = THANG;
}
// phuong thuc getter cua nam
int  Ngay::Getter_Nam() {
	return nam;
}
// phuong thuc setter cua nam
void Ngay::Setter_Nam(int NAM) {
	nam = NAM;
}

// Nhan Vien
NhanVien::NhanVien() {
    Ten = "";
    Ma = "";
    NoiSinh = "";
    NgaySinh.ngay = 0;
    NgaySinh.thang = 0;
    NgaySinh.nam = 0;
    LuongCoBan = 0;
    NamLamViec = 0;
    SoNgayNghi = 0;
}
NhanVien::~NhanVien(){}

void NhanVien::Doc_File(ifstream &filein) {
    getline(filein, Ten, ',');
    filein.seekg(1, 1); // dich con tro chi vi cua file tai vi tri hien tai sang ben phai 1 byte
	getline(filein, Ma, ',');
	filein.seekg(1, 1);
	getline(filein, NoiSinh, ',');
	int ngay;
	filein >> ngay;
	NgaySinh.Setter_Ngay(ngay);
	filein.seekg(1, 1);
	int thang;
	filein >> thang;
	NgaySinh.Setter_Thang(thang);
	filein.seekg(1, 1);
	int nam;
	filein >> nam;
	NgaySinh.Setter_Nam(nam);
	filein.seekg(2, 1);
	filein >> NamLamViec;
	filein.seekg(1, 1);
	filein >> SoNgayNghi;
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << Ten << endl;
    cout << "Ma nhan vien: " << Ma << endl;
    cout << "Noi sinh: " << endl;
    cout << "Ngay sinh: " << NgaySinh.Getter_Ngay() << "/" << NgaySinh.Getter_Thang() << "/" << NgaySinh.Getter_Nam() << endl;
    cout << "Nam lam viec: " << NamLamViec << endl;
    cout << "So ngay nghi: " << SoNgayNghi << endl;
}

float NhanVien::getLuong() {
    return this->LuongCoBan;
}

int NhanVien::getNamLamViec() {
	return this->NamLamViec;
}

int NhanVien::getSoNgayNghi() {
	return this->SoNgayNghi;
}

// Nhan Vien San Xuat
void NhanVienSanXuat::Doc_File(ifstream &filein) {
	NhanVien::Doc_File(filein);
	filein >> DonGiaMotSanPham;
	filein.seekg(1, 1);
	filein >> SoSanPham;
}

void NhanVienSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "Don gia mot san pham: " <<DonGiaMotSanPham<< endl;
	cout << "So san pham: " <<SoSanPham<< endl;
	this->TinhLuong();
	cout <<"Luong co ban: "<< LuongCoBan << endl;
	cout <<endl;
}

float NhanVienSanXuat::TinhLuong() {
	float Luong = 0;
	Luong = DonGiaMotSanPham*SoSanPham - getSoNgayNghi()*DonGiaMotSanPham*SoSanPham;
	if (getNamLamViec() >= 1 && getNamLamViec() <= 4) {
		Luong += 4500000;
	}
	if (getNamLamViec() <= 10) {
		Luong += 8000000;
	}
	else {
		Luong += 15000000;
	}
	return Luong;
}

// Nhan Vien Van Phong
void NhanVienVanPhong::Doc_File(ifstream &filein) {
	NhanVien::Doc_File(filein);
	filein >> HeSoLuong;
	filein.seekg(1, 1);
	filein >> SoNgayLam;
}

void NhanVienVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "He so luong: " <<HeSoLuong<< endl;
	cout << "So ngay lam: " <<SoNgayLam<< endl;
	this->TinhLuong();
	cout <<"Luong co ban: "<< LuongCoBan << endl;
	cout <<endl;
}

float NhanVienVanPhong::TinhLuong() {
	float Luong = 0;
	Luong = HeSoLuong*SoNgayLam(30 - getSoNgayNghi());
	if (getNamLamViec() >= 1 && getNamLamViec() <= 4) {
		Luong +=4500000;
	}
	if (getNamLamViec() <= 10) {
		Luong += 8000000;
	}
	else {
		Luong += 15000000;
	}
	return Luong;
}
