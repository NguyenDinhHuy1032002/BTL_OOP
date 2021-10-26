#pragma once
#include "Stack.h"

Stack::Stack() {
	this->top = NULL;
}

Stack::~Stack() {
	Node *p;
	while (top != NULL) {
		p = top;
		top = top->link;
		delete p;
	}
	top = NULL;
}

void Stack::push(NhanVien nv) {
	Node *p = new Node();
	p->data = nv;
	p->link = this->top;
	this->top = p;
}

NhanVien Stack::pop() {
	Node *p = this->top;
	NhanVien *nv = &p->data;
	this->top = this->top->link;
	delete p;
	return *nv;
}

NhanVien Stack::peek() {
	return this->top->data;
}

bool Stack::isEmpty() {
	return this->top == NULL;
}

string Stack::toSaveFile() {
	Stack *temp = new Stack();
	stringstream os;
	Node *p = this->top;
	
	while (p != NULL) {
		temp->push(p->data);
		p = p->link;
	}
	
	p = temp->top;
	while (p != NULL) {
		os << p->data.toLuuFile();
		p = p->link;
	}
	return os.str();
}

string Stack::toString() {
	Stack *temp = new Stack();
	Node *p = this->top;
	
	while (p != NULL) {
		temp->push(p->data);
		p = p->link;
	}
	
	stringstream os;
	if (this->isEmpty() == false) {
		os << L"\n\t\t\t\t\t	** DANH SACH NHAN VIEN **"
			<< L"\n\t+---------------------------------------------------------------------------------------------------+"
			<< L"\n\t¦" << setw(20) << L"Ho và tên   " << setw(5) << L"¦" << setw(20) << L"Chuc vu  " << setw(5) << L"¦" << setw(20) << L"Ngày sinh  " << setw(5) << L"¦" << setw(20) << L"He so luong  " << setw(5) << L"¦"
			<< L"\n\t+------------------------+------------------------+------------------------+------------------------¦";
		p = temp->top;
		while (p != NULL) {
			os << p->data.toString();
			if (p->link != NULL)
				os << L"\n\t+------------------------+------------------------+------------------------+------------------------¦";
			p = p->link; 
		}
		os << L"\n\t+---------------------------------------------------------------------------------------------------+";
	}
	return os.str();
}

string Stack::toStringSearch() {
	Stack *temp = new Stack();
	Node *p = this->top;
	
	while (p != NULL) {
		temp->push(p->data);
		p = p->link;
	}
	stringstream os;
	if (this->isEmpty() == false) {
		os << L"\n\t\t\t\t\t      ** DANH SÁCH NHÂN VIÊN **"
			<< L"\n\t+-------------------------------------------------------------------------------------------------------------+"
			<< L"\n\t¦" << setw(8) << L"STT  " << setw(2) << L"¦" << setw(20) << L"Ho và tên   " << setw(5) << L"¦" << setw(20) << L"Chuc vu  " << setw(5) << L"¦" << setw(20) << L"Ngày sinh  " << setw(5) << L"¦" << setw(20) << L"He so luong  " << setw(5) << L"¦"
			<< L"\n\t+---------+------------------------+------------------------+------------------------+------------------------¦";
		p = temp->top;
		int viTri = 1;
		while (p != NULL) {
			if (p->data.getViTri() == 0)
				p->data.setViTri(viTri);
			os << p->data.toStringSearch();
			p = p->link;
			viTri++;
		}
		os << L"\n\t+-------------------------------------------------------------------------------------------------------------+";	
	}
	return os.str();
}


















