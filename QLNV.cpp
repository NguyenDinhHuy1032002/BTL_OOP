#include "NhanVien.h"

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
    filein.ignore();
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
	cout << setw(12) << MaNV << setw(25) << HoTen << setw(20) << NoiSinh << setw(10);
	cout << NgaySinh.ngay << "/" << NgaySinh.thang << "/" << NgaySinh.nam << setw(20);
	cout << LuongCoBan << setw(27);
}

long NhanVien::getLuong() {
	return this->TinhLuong();
}

string NhanVien::getMaNV() {
	return this->MaNV;
}

string NhanVien::getTen() {
	return this->HoTen;
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
	cout << GiaMotSP << setw(30) << SoSP << setw(24) << this->TinhLuong() << setw(15) << endl;
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
	cout << HeSoLuong << setw(30) << SoNgayLam << setw(25) << this->TinhLuong() << setw(15) << endl;
}

long NhanVienVanPhong::TinhLuong() {
	return (this->getLuongCoBan()*HeSoLuong*SoNgayLam);
}

//Quan ly nhan vien
void QuanLyNhanVien::doc_File(ifstream& filein) {
	filein.open("dulieu.txt", ios_base::in);
	if(!filein.is_open()) {
		cout << "\t\tKhong tim thay file!";
	}
	else {
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
		cout << "\t\tDoc file thanh cong!";
		filein.close();
	}
}

void QuanLyNhanVien::Xuat_DS() {
	cout << "So luong nhan vien: " << n << endl;
	cout << "\n -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n||    MA NHAN VIEN    ||    HO VA TEN    ||    NOI SINH    ||    NGAY SINH    ||      LUONG CO BAN      ||    DON GIA/HE SO LUONG    ||    SO LUONG/SO NGAY LAM    ||    LUONG    ||";
    cout << "\n -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for(int i=0; i<n; i++) {
		nv[i]->Xuat();
		cout << endl;
	}
}

void QuanLyNhanVien::ThemNV() {
	system("cls");
	int viTriChon = 0, pos;
	NhanVien *NV;
	Menu *m = new Menu;
	vector<string> menu = {"NHAN VIEN SAN XUAT", "NHAN VIEN VAN PHONG", "TRO VE"};
	bool troVe = false;
	while (true) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\n\t\t\tChon loai nhan vien muon them\n\n";
		for (int i = 0; i < menu.size(); ++i) {
			if (viTriChon == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
				cout << "\n\t\t\t\t" << right << setw(5) << ">> " << left << setw(25) << menu[i];
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n\t\t\t\t" << right << setw(5) << "   " << left << setw(25) << menu[i];
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		int diChuyenPhim;
		if (_kbhit) {
			diChuyenPhim = m->phimDiChuyen();
			switch (diChuyenPhim) {
				case 1:
				case 3: {
					viTriChon += 1;
					if (viTriChon == menu.size())
						viTriChon = 0;
					break;
				}
				case 2:
				case 4: {
					viTriChon -= 1;
					if (viTriChon == -1)
						viTriChon = menu.size() - 1;
					break; 
				}
				case 5: {
					if (viTriChon == menu.size() - 1) {
						troVe = true;
						break;
					}
					else {
						system("cls");
						switch(viTriChon) {
							case 0:
								cout << "Nhap vi tri muon them: "; cin >> pos;
								NV = new NhanVienSanXuat;
								NV->Nhap();
								for(int i=n; i>pos; i--) {
									nv[i] = nv[i-1];
								}
								nv[pos] = NV;
								++n;
								Xuat_DS();
								system("pause");
								break;
							case 1:
								cout << "Nhap vi tri muon them: "; cin >> pos;
								NV = new NhanVienVanPhong;
								NV->Nhap();
								for(int i=n; i>pos; i--) {
									nv[i] = nv[i-1];
								}
								nv[pos] = NV;
								++n;
								Xuat_DS();
								system("pause");
								break;
							default:
								break;
						}
					}
					break;
				}
				default:
					break;
				}
			}
			if (troVe == true) {
				break;
		}
	}
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
	system("cls");
	vector<string> menu = { "THEO MA NHAN VIEN", "THEO HO VA TEN", "THEO NOI SINH", "THEO NAM SINH", "TRO VE" };
	int pointer = 0;
	bool troVe = false;
	Menu *m = new Menu;
	string ma, ten, ns;
	int nam;
	while (true) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		wcout << L"\n\t\t\t\tChon tieu chi tim kiem\n";
		for (int i = 0; i < menu.size(); ++i) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
				cout << "\n\t\t\t\t|" << right << setw(10) << ">>  " << left << setw(34) << menu[i] << right << setw(0) << "|";
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\n\t\t\t\t|" << right << setw(10) << "  " << left << setw(34) << menu[i] << right << setw(0) << "|";
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			int x;
			if (_kbhit) {
				x = m->phimDiChuyen();
				switch (x) {
				case 1:
				case 3: {
					pointer += 1;
					if (pointer == 5)
						pointer = 0;
					break; }
				case 2:
				case 4: {
					pointer -= 1;
					if (pointer == -1)
						pointer = 4;
					break; }
				case 5: {
					if (pointer == menu.size() - 1) {
						troVe = true;
						break;
					}
					else {
						int dem = 0;
						system("cls");
						switch(pointer) {
							case 0:
								cout << "\nNhap ma nhan vien muon tim: ";
								cin.ignore(); getline(cin, ma);
								for(int i=0; i<n; i++) {
									if(ma == nv[i]->getMaNV()) {
										nv[i]->Xuat();
										++dem;
									}
								}
								if(dem == 0)
									cout << "\nKhong tin thay nhan vien!\n";
								system("pause");
								break;
							case 1:
								cout << "\nNhap ten nhan vien muon tim: ";
								cin.ignore(); getline(cin, ten);
								for(int i=0; i<n; i++) {
									if(ten == nv[i]->getTen()) {
										nv[i]->Xuat();
										++dem;
									}
								}
								if(dem == 0)
									cout << "\nKhong tim thay nhan vien!\n";
								system("pause");
								break;
							case 2:
								cout << "\nNhap noi sinh muon tim: ";
								cin.ignore(); getline(cin, ns);
								for(int i=0; i<n; i++) {
									if(ns == nv[i]->getNoiSinh()) {
										nv[i]->Xuat();
										++dem;
									}
								}
								if(dem == 0)
									cout << "\nKhong tim thay nhan vien!\n";
								system("pause");
								break;
							case 3:
								cout << "\nNhap nam sinh muon tim: ";
								cin.ignore(); cin >> nam;
								for(int i=0; i<n; i++) {
									if(nam == nv[i]->getNamSinh()) {
										nv[i]->Xuat();
										++dem;
									}
								}
								if(dem == 0)
									cout << "\nKhong tim thay nhan vien!\n";
								system("pause");
								break;
							default:
								break;
						}
					}
					break;
				}
				default:
					break;
				}
			}
			if (troVe == true) {
				break;
		}
	}
}

void HoanVi(NhanVien *&nv1, NhanVien *&nv2) {
	NhanVien *nv3;
	nv3 = nv1;
	nv1 = nv2;
	nv2 = nv3;
}

void QuanLyNhanVien::SapXep() {
	system("cls");
	vector<string> menu = { "THEO MA NHAN VIEN", "THEO HO VA TEN", "THEO NOI SINH", "THEO NAM SINH", "THEO LUONG", "TRO VE" };
	int pointer = 0;
	Menu *m = new Menu;
	bool troVe = false;
	while (true) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\t\t\t\tChon tieu chi sap xep\n";
		for (int i=0; i<menu.size(); ++i) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
				cout << "\n\t\t\t\t|" << right << setw(10) << ">>  " << left << setw(34) << menu[i] << right << setw(0) << "|";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n\t\t\t\t|" << right << setw(10) << "  " << left << setw(34) << menu[i] << right << setw(0) << "|";
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		int x;
		if (_kbhit) {
			x = m->phimDiChuyen();
			switch (x) {
				case 1:
				case 3: {
					pointer += 1;
					if (pointer == 6)
						pointer = 0;
					break; }
				case 2:
				case 4: {
					pointer -= 1;
					if (pointer == -1)
						pointer = 5;
					break; }
				case 5: {
					if (pointer == menu.size() - 1) {
						troVe = true;
						break;
					}
					else {
						system("cls");
						vector<string> menuChon;
						int vitriChon = 0;
						Menu *k = new Menu;
						bool quayLai = false;
						switch(pointer) {
							case 0: 
								menuChon = { "CHIEU XUOI", "CHIEU NGUOC", "QUAY LAI" };
								while (true) {
									system("cls");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << "\n\t\t\t\tChon chieu sap xep\n";
									for (int i=0; i<menuChon.size(); ++i) {
										if (i == vitriChon) {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
											cout << "\n\t\t\t\t|" << right << setw(10) << ">>  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
										else {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
											cout << "\n\t\t\t\t|" << right << setw(10) << "  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									int v;
									v = k->phimDiChuyen();
									switch (v) {
										case 1:
										case 3: {
											vitriChon += 1;
											if (vitriChon == 3)
												vitriChon = 0;
											break; }
										case 2:
										case 4: {
											vitriChon -= 1;
											if (vitriChon == -1)
												vitriChon = 2;
											break; }
										case 5: {
											if(vitriChon == menuChon.size() - 1) {
												quayLai = true;
												break;
											}
											else {
												system("cls");
												switch(vitriChon) {
													case 0:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																char* str1 = new char[nv[i]->getMaNV().length()];
																strcpy(str1, nv[i]->getMaNV().c_str());
																char* str2 = new char[nv[j]->getMaNV().length()];
																strcpy(str2, nv[j]->getMaNV().c_str());
																if(strcmp(str1, str2) > 0) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													case 1:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																char* str1 = new char[nv[i]->getMaNV().length()];
																strcpy(str1, nv[i]->getMaNV().c_str());
																char* str2 = new char[nv[j]->getMaNV().length()];
																strcpy(str2, nv[j]->getMaNV().c_str());
																if(strcmp(str1, str2) < 0) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													default:
														break;
												}
											}
											break;
										}
										default:
											break;
									}
									if (quayLai == true)
										break;
								}
								break;	
							case 1:
								menuChon = { "CHIEU XUOI", "CHIEU NGUOC", "QUAY LAI" };
								while (true) {
									system("cls");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << "\n\t\t\t\tChon chieu sap xep\n";
									for (int i=0; i<menuChon.size(); ++i) {
										if (i == vitriChon) {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
											cout << "\n\t\t\t\t|" << right << setw(10) << ">>  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
										else {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
											cout << "\n\t\t\t\t|" << right << setw(10) << "  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									int v;
									v = k->phimDiChuyen();
									switch (v) {
										case 1:
										case 3: {
											vitriChon += 1;
											if (vitriChon == 3)
												vitriChon = 0;
											break; }
										case 2:
										case 4: {
											vitriChon -= 1;
											if (vitriChon == -1)
												vitriChon = 2;
											break; }
										case 5: {
											if(vitriChon == menuChon.size() - 1) {
												quayLai = true;
												break;
											}
											else {
												system("cls");
												switch(vitriChon) {
													case 0:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																char* str1 = new char[nv[i]->getTen().length()];
																strcpy(str1, nv[i]->getTen().c_str());
																char* str2 = new char[nv[j]->getTen().length()];
																strcpy(str2, nv[j]->getTen().c_str());
																if(strcmp(str1, str2) > 0) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													case 1:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																char* str1 = new char[nv[i]->getTen().length()];
																strcpy(str1, nv[i]->getTen().c_str());
																char* str2 = new char[nv[j]->getTen().length()];
																strcpy(str2, nv[j]->getTen().c_str());
																if(strcmp(str1, str2) < 0) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													default:
														break;
												}
											}
											break;
										}
										default:
											break;
									}
									if (quayLai == true)
										break;
								}
								break;		
							case 2:
								menuChon = { "CHIEU XUOI", "CHIEU NGUOC", "QUAY LAI" };
								while (true) {
									system("cls");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << "\n\t\t\t\tChon chieu sap xep\n";
									for (int i=0; i<menuChon.size(); ++i) {
										if (i == vitriChon) {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
											cout << "\n\t\t\t\t|" << right << setw(10) << ">>  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
										else {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
											cout << "\n\t\t\t\t|" << right << setw(10) << "  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									int v;
									v = k->phimDiChuyen();
									switch (v) {
										case 1:
										case 3: {
											vitriChon += 1;
											if (vitriChon == 3)
												vitriChon = 0;
											break; }
										case 2:
										case 4: {
											vitriChon -= 1;
											if (vitriChon == -1)
												vitriChon = 2;
											break; }
										case 5: {
											if(vitriChon == menuChon.size() - 1) {
												quayLai = true;
												break;
											}
											else {
												system("cls");
												switch(vitriChon) {
													case 0:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																char* str1 = new char[nv[i]->getNoiSinh().length()];
																strcpy(str1, nv[i]->getNoiSinh().c_str());
																char* str2 = new char[nv[j]->getNoiSinh().length()];
																strcpy(str2, nv[j]->getNoiSinh().c_str());
																if(strcmp(str1, str2) > 0) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													case 1:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																char* str1 = new char[nv[i]->getNoiSinh().length()];
																strcpy(str1, nv[i]->getNoiSinh().c_str());
																char* str2 = new char[nv[j]->getNoiSinh().length()];
																strcpy(str2, nv[j]->getNoiSinh().c_str());
																if(strcmp(str1, str2) < 0) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													default:
														break;
												}
											}
											break;
										}
										default:
											break;
									}
									if (quayLai == true)
										break;
								}
								break;	
							case 3:
								menuChon = { "TANG DAN", "GIAM DAN", "QUAY LAI" };
								while (true) {
									system("cls");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << "\n\t\t\t\tChon chieu sap xep\n";
									for (int i=0; i<menuChon.size(); ++i) {
										if (i == vitriChon) {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
											cout << "\n\t\t\t\t|" << right << setw(10) << ">>  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
										else {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
											cout << "\n\t\t\t\t|" << right << setw(10) << "  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									int v;
									v = k->phimDiChuyen();
									switch (v) {
										case 1:
										case 3: {
											vitriChon += 1;
											if (vitriChon == 3)
												vitriChon = 0;
											break; }
										case 2:
										case 4: {
											vitriChon -= 1;
											if (vitriChon == -1)
												vitriChon = 2;
											break; }
										case 5: {
											if(vitriChon == menuChon.size() - 1) {
												quayLai = true;
												break;
											}
											else {
												system("cls");
												switch(vitriChon) {
													case 0:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																if(nv[i]->getNamSinh() > nv[j]->getNamSinh()) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													case 1:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																if(nv[i]->getNamSinh() < nv[j]->getNamSinh()) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													default:
														break;
												}
											}
											break;
										}
										default:
											break;
									}
									if (quayLai == true)
										break;
								}
								break;	
							case 4:
								menuChon = { "LON DAN", "NHO DAN", "QUAY LAI" };
								while (true) {
									system("cls");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << "\n\t\t\t\tChon chieu sap xep\n";
									for (int i=0; i<menuChon.size(); ++i) {
										if (i == vitriChon) {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
											cout << "\n\t\t\t\t|" << right << setw(10) << ">>  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
										else {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
											cout << "\n\t\t\t\t|" << right << setw(10) << "  " << left << setw(34) << menuChon[i] << right << setw(0) << "|";
										}
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									int v;
									v = k->phimDiChuyen();
									switch (v) {
										case 1:
										case 3: {
											vitriChon += 1;
											if (vitriChon == 3)
												vitriChon = 0;
											break; }
										case 2:
										case 4: {
											vitriChon -= 1;
											if (vitriChon == -1)
												vitriChon = 2;
											break; }
										case 5: {
											if(vitriChon == menuChon.size() - 1) {
												quayLai = true;
												break;
											}
											else {
												system("cls");
												switch(vitriChon) {
													case 0:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																if(nv[i]->getLuong() > nv[j]->getLuong()) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													case 1:
														for(int i=0; i<n-1; i++) {
															for(int j=n-1; j>i; j--) {
																if(nv[i]->getLuong() < nv[j]->getLuong()) {
																	HoanVi(nv[i], nv[j]);
																} 
															}
														}
														Xuat_DS();
														system("pause");
														break;
													default:
														break;
												}
											}
											break;
										}
										default:
											break;
									}
									if (quayLai == true)
										break;
								}
								break;	
							default:
								break;
						}	
					}
					break;
				}
				default:
					break;
			}
		}
		if (troVe == true)
				break;	
	}
}

Menu::Menu() {}

int Menu::phimDiChuyen() {
	char c = _getch();
	if ((int)c == -32) c = _getch();
	switch ((int)c) {
		case 80:
			return 1; //cout << "Xuong";
		case 72:
			return 2; //cout << "Len";
		case 77:
			return 3; //cout << "Phai";       
		case 75:
			return 4; //cout << "Trai";
		case 27:
			return 8; //Nut ESC thoat
		case 13:
			return 5; //Nut Enter
		default:
			return 0; //cout << "Sai";
	}
}

int MENU() {
	vector<string> menu = { "DOC DU LIEU TU FILE", "XEM DANH SACH NHAN VIEN", "SAP XEP NHAN VIEN", "THEM NHAN VIEN", "XOA NHAN VIEN", "TIM KIEM", "THOAT CHUONG TRINH" };
	int pointer = 0;
	ifstream file;
	QuanLyNhanVien *QLVN = new QuanLyNhanVien;
	Menu *m = new Menu;
	while (true) {
		fflush(stdin);
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\t\t\t         | >>>>>>> HE THONG QUAN LY NHAN VIEN <<<<<<< |";
		for (int i = 0; i < menu.size(); i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 125);
				cout << "\n\t\t\t\t |" << right << setw(10) << ">>  " << left << setw(34) << menu[i] << right << setw(0) << "|";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n\t\t\t\t |" << right << setw(10) << "    " << left << setw(34) << menu[i] << right << setw(0) << "|";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		int x;
		bool thoat = false;
		if (_kbhit) {
			x = m->phimDiChuyen();
			switch (x) {
			case 1:
			case 3: {
				pointer += 1;
				if (pointer == menu.size())
					pointer = 0;
				thoat = true;
				break; }
			case 2:
			case 4: {
				pointer -= 1;
				if (pointer == -1)
					pointer = menu.size() - 1;
				thoat = true;
				break; }
			case 5: {
				bool daDoc = false;
				switch (pointer) {
				case 0:
					cout << "\nBan da chon doc file nhan vien!\n";
					system("cls");
					QLVN->doc_File(file);
					daDoc = true;
					cout << "\n\t\tNhan phim bat ky de tiep tuc!\n";
					getch();
					break; 
				case 1:
					system("cls");
					if(daDoc) {
						cout << "\nBan da chon xuat danh sach nhan vien!\n";
						QLVN->Xuat_DS();
					}else{
						cout << "\n\t\tVui long doc file nhan vien truoc!\n";
					}
					cout << "\n\t\tNhan phim bat ky de tiep tuc!\n";
					getch();
					break; 
				case 2:
					if(daDoc) {
						cout << "\nBan da chon sap xep nhan vien!\n";
						QLVN->SapXep();
					}else {
						cout << "\n\t\tVui long doc file nhan vien truoc!\n";
					}
					cout << "\n\t\tNhan phim bat ky de tiep tuc!\n";
					getch();
					break;
				case 3:
					system("cls");
					if(daDoc) {
						cout << "\nBan da chon them nhan vien!\n";
						QLVN->ThemNV();
					}else {
						cout << "\n\t\tVui long doc file nhan vien truoc!\n";
					}
					cout << "\n\t\tNhan phim bat ky de tiep tuc!\n";
					getch();
					break;
				case 4:
					system("cls");
					if(daDoc) {
						cout << "\nBan da chon xoa nhan vien!\n";
						QLVN->XoaNV();
					}else {
						cout << "\n\t\tVui long doc file nhan vien truoc!\n";
					}
					cout << "\n\t\tNhan phim bat ky de tiep tuc!\n";
					getch();
					break;
				case 5:
					system("cls");
					if(daDoc) {
						cout << "\nBan da chon tim kiem nhan vien!\n";
						QLVN->TimKiem();
					}else {
						cout << "\n\t\tVui long doc file nhan vien truoc!\n";
					}
					cout << "\n\t\tNhan phim bat ky de tiep tuc!\n";
					getch();
					break;
				default:
					return 0;
					break;
				}
				thoat = true;
				break;
			}
			default:
				break;
			}
		}
	}
}

int main() {
	MENU();
}
