#include "DSLK.h"

void Khoi_Tao_List (List &l) {
	l.head = l.tail = NULL;
}

void Nhap_ThongTin(nhanvien *nv) {
	cin.ignore();
	cout << "Nhap ma nhan vien: "; getline(cin, nv->Ma);
	cout << "Nhap ten nhan vien: "; getline(cin, nv->Name);
	cout << "Nhap noi sinh: "; getline(cin, nv->NoiSinh);
	cout << "Nhap ngay sinh: "; getline(cin, nv->NgaySinh);
	cout << "Nhap chuc vu: "; getline(cin, nv->ChucVu);
}

Node *Khoi_Tao_Node() {
	nhanvien* nv = new nhanvien;
	Nhap_ThongTin(nv);
	Node* p = new Node;
	if (p == NULL) {
		cout << "Full bo nho khong the tao them";
		return 0;
	}
	p->data = nv;
	p->link = NULL;
	return p;
}

void ThemVaoDauMotNhanVien (List &l, Node *p) {
	if (l.head == NULL) {
		l.head = l.tail = p;
	}
	else {
		p->link = l.head;
		l.head = p;
	}
}

void Show (List l) {
	for (Node* k = l.head; k != NULL; k = k->link) {
		cout << "MSNV: " << k->data->Ma << endl;
		cout << "Ho ten: " << k->data->Name << endl;
		cout << "Noi sinh: " << k->data->NoiSinh << endl;
		cout << "Ngay sinh: " << k->data->NgaySinh << endl;
		cout << "Chuc vu: " << k->data->ChucVu << endl;
		cout << "Luong co ban: " << k->data->LuongCoBan << endl;
	}
}

void showNode(Node *k) {
	cout << "==============================NV================\n";
	cout << "MSNV: " << k->data->Ma << endl;
	cout << "Ho ten: " << k->data->Name << endl;
	cout << "Noi sinh: " << k->data->NoiSinh << endl;
	cout << "Ngay sinh: " << k->data->NgaySinh << endl;
	cout << "Chuc vu: " << k->data->ChucVu << endl;
	cout << "Luong co ban: " << k->data->LuongCoBan << endl;
}



void XoaNhanVien (List &l) {
	string xoa;
	cin.ignore();
	cout << "Nhap Ma so NV hoac Ten NV can xoa: " << endl;
	getline(cin, xoa);
	Node* g = new Node;
	if (xoa.compare(l.head->data->Name) == 0 && l.head->link == NULL) {
		l.head = NULL;
	}
	else {
		for (Node *k = l.head; k != NULL; k = k->link) {
			if (xoa.compare(k->data->Name) == 0) {
				g->link = k->link;
				k = g;
			}
			g = k;
		}
	}
}

void search (List l) {
	string Ma;
	cout << "Nhap Ma So Nhan Vien Can Tim Kiem: " << endl;
	cin >> Ma;
	for (Node *k = l.head; k != NULL; k = k->link) {
		if (k->data->Ma == Ma) {
			showNode(k);
		}
	}
}

void Upgrade (List &l) {
	string Ma;
	cout << "Nhap ma so nhan vien can chinh sua: " << endl;
	cin >> Ma;
	for (Node *k = l.head; k != NULL; k = k->link) {
		if (k->data->Ma == Ma) {
			cout << "Moi ban sua thong tin nhan vien co ma so: " << Ma << endl;
			Nhap_ThongTin(k->data);
		}
	}
}

void Menu (List &l) {
	int n;
	cout << "\t\t======Danh Sach Chuc Nang=========" << endl;
	cout << "=> \t1. Nhap 1 nhan vien moi ." << endl;
	cout << "=> \t2. In danh sach nhan vien . " << endl;
	cout << "=> \t3. Tim kiem nhan vien theo ma so ." << endl;
	cout << "=> \t4. Sua thong tin nhan vien." << endl;
	cout << "=> \t5. Xoa nhan vien khoi danh sach." << endl;
	cout << "=> \t0. Thoat chuong trinh" << endl;
	while (true) {
		cout << "Nhap chuc nang ban chon : ";
		cin >> n;
		if (n == 1) {
			cout << "Moi Ban nhap thong tin 1 nhan vien : " << endl;
			Node* p = Khoi_Tao_Node();
			ThemVaoDauMotNhanVien(l, p);
		}
		if (n == 3) {
			search(l);
		}
		if (n == 2) {
			cout << "Danh Sach Sinh Vien : \n";
			Show(l);
		}
		if (n == 4) {
			Upgrade(l);
		}
		if (n == 5) {
			XoaNhanVien(l);
		}
		if (n == 0) {
			break;
		}
	}	
	
}

int main() {
	List l;
	Khoi_Tao_List(l);
	Menu(l);
	system("pause");
	return 0;
}

















