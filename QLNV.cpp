#include"QLNV.hpp"

//Nhan vien
void NhanVien::Doc_File(ifstream& filein) {
    getline(filein, Ma, ',');
    getline(filein, HoTen, ',');
    Doc_Ngay(filein, NgaySinh);
    filein >> LuongCoBan;
    filein.ignore();
}

void NhanVien::Xuat() {
    cout << Ma << setw(20) << HoTen << setw(12) << NgaySinh.ngay << "/" <<NgaySinh.thang << "/" << NgaySinh.nam << setw(17) << LuongCoBan << setw(20); 
}

long NhanVien::getLuong() {
    return this->TinhLuong();
}

long NhanVien::getLuongCoBan() {
    return this->LuongCoBan;
}

//Nhan vien san xuat
void NhanVienSanXuat::Doc_File(ifstream& filein) {
    NhanVien::Doc_File(filein);
    filein >> GiaMotSP;
    filein.ignore();
    filein >> SoSP;
    filein.ignore();
}

void NhanVienSanXuat::Xuat() {
    NhanVien::Xuat();
    cout << GiaMotSP << setw(32) << SoSP << setw(27) << this->TinhLuong() << endl;
}

long NhanVienSanXuat::TinhLuong() {
    long Luong = 0;
    Luong = this->getLuongCoBan() + GiaMotSP*SoSP;
    return Luong;
}

//Nhan vien van phong
void NhanVienVanPhong::Doc_File(ifstream& filein) {
    NhanVien::Doc_File(filein);
    filein >> HeSoLuong;
    filein.ignore();
    filein >> SoNgayLam;
    filein.ignore();
}

void NhanVienVanPhong::Xuat() {
    NhanVien::Xuat();
    cout << HeSoLuong << setw(32) << SoNgayLam << setw(27) << this->TinhLuong() << endl;
}

long NhanVienVanPhong::TinhLuong() {
    long Luong = 0;
    Luong = this->getLuongCoBan()*HeSoLuong*SoNgayLam;
    return Luong; 
}

void QLNV(NhanVien *nv[], int &n) {
    ifstream filein;
    filein.open("DLNV.txt", ios_base::in);
    int choose;
    while(true) {
        system("cls");
        cout << "\n1. Doc thong tin tu file.";
        cout << "\n2. Xuat danh sach sinh vien.";
        cout << "\n0. Ket thuc.";
        cout << "\nNhap lua chon: ";
        cin  >> choose;
        if(choose == 1){
            filein >> n;
            filein.ignore();
            for(int i=0; i<n; i++) {
                char c;
                filein >> c;
                NhanVien *NV;
                if(c == 'P'){
                    NV = new NhanVienSanXuat;
                    NV->Doc_File(filein);
                }
                else if(c == 'O') {
                    NV = new NhanVienVanPhong;
                    NV->Doc_File(filein);
                }
                nv[i] = NV;
            }
            cout << "\nDoc thong tin thanh cong !";
            system("pause");
        }
        else if(choose == 2) {
            cout << "\nSo luong nhan vien: " << n << endl;
            cout << "Ma" << setw(20) << "Ho ten" << setw(20) << "Ngay sinh" << setw(20) << "Luong co ban" << setw(30) << "Gia 1 san pham/He so luong" << setw(30) << "So san pham/So ngay lam" << setw(15) << "Luong" << endl;
            for(int i=0; i<n; i++) {
                nv[i]->Xuat();
                cout << endl;
            }
            system("pause");
        }
        else {
            break;
        }
    }
    filein.close();
}

int main() {
    NhanVien *nv[100];
    int  n = 0;
    QLNV(nv, n);
}