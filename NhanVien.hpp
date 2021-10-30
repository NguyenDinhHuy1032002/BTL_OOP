#include <iostream>
#include <iomanip>
using namespace std;

class Ngay {
    private:
    	int ngay;
    	int thang;
    	int nam;
    public:
    	int Getter_Ngay();
	int Setter_Ngay(int NGAY);
    	int Getter_Thang(); 
	int Setter_Thang(int THANG);
	int Getter_Nam(); 
	int Setter_Nam(int NAM);  	
};

class NhanVien {
    protected:
        string Ten;
        string Ma;
        string NoiSinh;
        Ngay NgaySinh;
        float LuongCoBan;
        int NamLamViec;
        int SoNgayNghi;
    public:
        NhanVien();
        ~NhanVien();
        virtual void Doc_File(ifstream &);
        virtual void Xuat();
        virtual float TinhLuong() = 0;
        virtual float getLuong();
        virtual int getNamLamViec();
        virtual int getSoNgayNghi();
};

class NhanVienSanXuat : public NhanVien {
	private:
		float DonGiaMotSanPham;
		int SoSanPham;
	public:
		void Doc_File(ifstream &);
		void Xuat();
		float TinhLuong();
};

class NhanVienVanPhong : public NhanVien {
	private:
		float HeSoLuong;
		int SoNgayLam;
	public:
		void Doc_File(ifstream &);
		void Xuat();
		float TinhLuong();
};


