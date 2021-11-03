#include "QLNV.hpp"

void doc_Ngay(ifstream& filein, Date &NgaySinh) {
	filein >> NgaySinh.ngay;
	filein.ignore();
	filein >> NgaySinh.thang;
	filein.ignore();
	filein >> NgaySinh.nam;
	filein.ignore();
}

//Nhan vien
NhanVien::NhanVien() {
	MaNV = "";
	HoTen = "";
	NoiSinh = "";
	NgaySinh.ngay = 0;
	NgaySinh.thang = 0;
	NgaySinh.nam = 0;
	LuongCoBan = 0;
}

NhanVien::~NhanVien() {
}

void NhanVien::doc_File(ifstream& filein) {
	getline(filein, MaNV, ',');
	filein.ignore();
	getline(filein, HoTen, ',');
	filein.ignore();
	getline(filein, NoiSinh, ',');
	doc_Ngay(filein, NgaySinh);
	filein >> LuongCoBan;
	filein.ignore();
}

void NhanVien::Nhap() {
	cout << "Nhap ma nhan vien: ";
	cin.ignore();
	getline(cin, MaNV);
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	cout << "Nhap noi sinh: ";
	getline(cin, NoiSinh);
	cout << "Nhap ngay sinh: ";
	cin >> NgaySinh.ngay >> NgaySinh.thang >> NgaySinh.nam;
	cin.ignore();
	cout << "Nhap luong co ban: ";
	cin >> LuongCoBan;
}

void NhanVien::Xuat() {
	cout << "Ma nhan vien: " << MaNV << endl;
	cout << "Ho ten: " << HoTen << endl;
	cout << "Noi sinh: " << NoiSinh << endl;
	cout << "Ngay sinh: " << NgaySinh.ngay << "/" << NgaySinh.thang << "/" << NgaySinh.nam << endl;
	cout << "Luong co ban: " << LuongCoBan << endl;
}

long NhanVien::getLuong() {
	return this->TinhLuong();
}

string NhanVien::getMaNV() {
	return this->MaNV;
}

string NhanVien::getNoiSinh() {
	return this->NoiSinh;
}

int NhanVien::getNamSinh() {
	return this->NgaySinh.nam;
}

long NhanVien::getLuongCoBan() {
	return this->LuongCoBan;
}

//Nhan vien san xuat
NhanVienSanXuat::NhanVienSanXuat() {
	GiaMotSP = 0;
	SoSP = 0;
}

NhanVienSanXuat::~NhanVienSanXuat() {
}

void NhanVienSanXuat::doc_File(ifstream& filein) {
	NhanVien::doc_File(filein);
	filein >> GiaMotSP;
	filein.ignore();
	filein >> SoSP;
	filein.ignore();
}

void NhanVienSanXuat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap gia 1 san pham: ";
	cin >> GiaMotSP;
	cout << "Nhap so san pham: ";
	cin >> SoSP;
}

void NhanVienSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "Gia 1 san pham: " << GiaMotSP << endl;
	cout << "So san pham: " << SoSP << endl;
	cout << "Luong: " << this->TinhLuong() << endl;
}

long NhanVienSanXuat::TinhLuong() {
	return (this->getLuongCoBan() + GiaMotSP*SoSP);
}

//Nhan vien van phong
NhanVienVanPhong::NhanVienVanPhong() {
	HeSoLuong = 0;
	SoNgayLam = 0;
}

NhanVienVanPhong::~NhanVienVanPhong() {
}

void NhanVienVanPhong::doc_File(ifstream& filein) {
	NhanVien::doc_File(filein);
	filein >> HeSoLuong;
	filein.ignore();
	filein >> SoNgayLam;
	filein.ignore();
}

void NhanVienVanPhong::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap he so luong: ";
	cin >> HeSoLuong;
	cout << "Nhap so ngay lam: ";
	cin >> SoNgayLam;
}

void NhanVienVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "He so luong: " << HeSoLuong << endl;
	cout << "So ngay lam: " << SoNgayLam << endl;
	cout << "Luong: " << this->TinhLuong() << endl;
}

long NhanVienVanPhong::TinhLuong() {
	return (this->getLuongCoBan()*HeSoLuong*SoNgayLam);
}

//Quan ly nhan vien
void QuanLyNhanVien::doc_File(ifstream& filein) {
	filein >> n;
	filein.ignore();
	for(int i=0; i<n; i++) {
		NhanVien *NV;
		char c;
		filein >> c;
		if(c == 'P') {
			NV = new NhanVienSanXuat;
			NV->doc_File(filein);
		}
		else if(c == 'O') {
			NV = new NhanVienVanPhong;
			NV->doc_File(filein);
		}
		nv[i] = NV;
	}
}

void QuanLyNhanVien::Xuat_DS() {
	cout << "\nSo luong nhan vien: " << n << endl;
	cout << "===================DANH SACH NHAN VIEN======================" << endl;
	for(int i=0; i<n; i++) {
		nv[i]->Xuat();
		cout << endl;
	}
}

void QuanLyNhanVien::ThemNV() {
	NhanVien *NV;
	int pos, key;
	cout << "Nhap vi tri muon them: "; cin >> pos;
	system("cls");
	cout << "\n1. Nhan vien san xuat.";
	cout << "\n2. Nhan vien van phong.";
	cout << "\nNhap lua chon: "; cin >> key;
	if(key == 1) {
		NV = new NhanVienSanXuat;
		NV->Nhap();
	}
	else if(key == 2) {
		NV = new NhanVienVanPhong;
		NV->Nhap();
	}
	for(int i=n; i>pos; i--) {
		nv[i] = nv[i-1];
	}
	nv[pos] = NV;
	++n;
	Xuat_DS();
}

void QuanLyNhanVien::XoaNV() {
	int pos;
	cout << "\nNhap vi tri can xoa: "; cin >> pos;
	for(int i=pos; i<n-1; i++) {
		nv[i] = nv[i+1];
	}
	--n;
	Xuat_DS();
}

void QuanLyNhanVien::TimKiem() {
	int key, dem = 0;
	system("cls");
	cout << "\n1. Tim kiem theo ma nhan vien.";
	cout << "\n2. Tim kiem theo noi sinh.";
	cout << "\n3. Tim kiem theo nam sinh.";
	cout << "\nNhap lua chon: "; cin >> key;
	if(key == 1) {
		string MNV;
		cout << "Nhap ma nhan vien can tim: ";
		cin.ignore();
		getline(cin, MNV);
		for(int i=0; i<n; i++) {
			if(nv[i]->getMaNV() == MNV) {
				nv[i]->Xuat();
				cout << endl;
				dem++;
			}
		}
		if(dem == 0)
			cout << "\nKhong co nhan vien nao co ma nay!";
		dem = 0;
	}
	else if(key == 2) {
		string NS;
		cout << "Nhap noi sinh can tim: ";
		cin.ignore();
		getline(cin, NS);
		for(int i=0; i<n; i++) {
			if(nv[i]->getNoiSinh() == NS) {
				nv[i]->Xuat();
				cout << endl;
				dem++;
			}
		}
		if(dem == 0)
			cout << "\nKhong co nhan vien nao co noi sinh nay!";
		dem = 0;
	}
	else if(key == 3) {
		int nam;
		cout << "\nNhap nam sinh can tim: ";
		cin >> nam;
		for(int i=0; i<n; i++) {
			if(nv[i]->getNamSinh() == nam) {
				nv[i]->Xuat();
				cout << endl;
				dem++;
			}
		}
		if(dem == 0)
			cout << "\nKhong co nhan vien nao co nam sinh nay!";
	}
}

void Swap(NhanVien *nv1, NhanVien *nv2) {
	NhanVien *nv3 = nv1;
	nv1 = nv2;
	nv2 = nv3;
}

void QuanLyNhanVien::SapXep() {
	int key;
	system("cls");
	cout << "\n1. Sap xep theo ma nhan vien.";
	cout << "\n2. Sap xep theo noi sinh.";
	cout << "\n3. Sap xep theo nam sinh.";
	cout << "\n4. Sap xep theo luong.";
	cout << "\nNhap lua chon: "; cin >> key;
	if(key == 1) {
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(nv[i]->getMaNV() > nv[j]->getMaNV())
					Swap(nv[i], nv[j]);
			}
		}
	}
	else if(key == 2) {
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(nv[i]->getNoiSinh() > nv[j]->getNoiSinh())
					Swap(nv[i], nv[j]);
			}
		}
	}
	else if(key == 3) {
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(nv[i]->getNamSinh() > nv[j]->getNamSinh())
					Swap(nv[i], nv[j]);
			}
		}
	}
	else if(key == 4) {
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(nv[i]->getLuong() > nv[j]->getLuong())
					Swap(nv[i], nv[j]);
			}
		}
	}
	Xuat_DS();
}

int Menu() {
	int key;
	ifstream filein;
	QuanLyNhanVien *QLNV = new QuanLyNhanVien;
	filein.open("dulieu.txt", ios_base::in);
	bool daDoc = false;
	while(true) {
		system("cls");
		cout << "\n************************ DANH SACH CHUC NANG *************************" << endl;
        cout << "**                     1. Doc thong tin nhan vien                   **" << endl;
        cout << "**                     2. Xuat thong tin nhan vien                  **" << endl;
        cout << "**                     3. Them nhan vien                            **" << endl;
        cout << "**                     4. Xoa nhan vien                             **" << endl;
        cout << "**                     5. Tim kiem nhan vien                        **" << endl;
        cout << "**                     6. Sap xep nhan vien                         **" << endl;
        cout << "**                     0. Thoat                                     **" << endl;
        cout << "**********************************************************************" << endl;
        cout <<"Nhap chuc nang: ";
        cin >> key;
        switch(key) {
			case 1:
				cout << "\nBan da chon doc thong tin nhan vien!!!\n" << endl;
				QLNV->doc_File(filein);
				daDoc = true;
				cout << "\nBan da doc thanh cong!";
				cout << "\nNhan phim bat ky de tiep tuc!";
				getch();
				break;
			case 2:
				if(daDoc){
					cout << "\nBan da chon xuat thong tin nhan vien!!!\n" << endl;
					QLNV->Xuat_DS();
					cout << "\nBan da xuat thanh cong!";
				}else{
					cout << "\nVui long doc thong tin truoc!!!";
				}
				cout << "\nNhan phim bat ky de tiep tuc!";
				getch();
				break;
            case 3:
                if(daDoc){
                    cout << "\nBan da chon them nhan vien!!!\n";
                    QLNV->ThemNV();
                }
                else{
                    cout << "\nVui long doc thong tin truoc!!!";
                }
                cout << "\nNhan phim bat ky de tiep tuc!";
                getch();
                break;
            case 4: 
                if(daDoc){
                    cout << "\nBan da chon xoa nhan vien!!!\n";
                    QLNV->XoaNV();
                }
                else{
                    cout << "\nVui long doc thong tin truoc!!!";
                }
                cout << "\nNhan phim bat ky de tiep tuc!";
                getch();
                break;
            case 5:
            	if(daDoc){
            		cout << "\nBan da chon tim kiem nhan vien!!!\n";
            		QLNV->TimKiem();
				}
				else{
					cout << "\nVui long doc thong tin nhan vien truoc!!!";
				}
				cout << "\nNhap phim bat ky de tiep tuc!";
				getch();
				break;
			case 6:
				if(daDoc){
					cout << "\nBan da chon sap xep nhan vien!!!\n";
					QLNV->SapXep();
				}
				else{
					cout << "\nVui long doc thong tin nhan vien truoc!!!";
				}
				cout << "\nNhap phim bat ky de tiep tuc!";
				getch();
				break;
			case 0:
				cout << "\nBan da chon thoat chuong trinh!!!\n";
				return 0;
			default:
				cout << "\nChuc nang nay hien khong co, vui long nhap lai!";
				getch();
				break;
		}
	}
	filein.close();
}

int main() {
	Menu();
}
