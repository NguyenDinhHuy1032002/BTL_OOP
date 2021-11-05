#include <iostream>
#include <string>
using namespace std;

struct Ngay {
	int ngay, thang, nam;
};

struct NhanVien {
	string Ma;
	string Name;
	string NoiSinh;
	string NgaySinh;
	string ChucVu;
	long LuongCoBan;
};
typedef struct NhanVien nhanvien;

struct node {
	nhanvien *data;
	struct node *link;
};
typedef struct node Node;

struct list {
	Node* head;
	Node* tail;
};
typedef struct list List;
