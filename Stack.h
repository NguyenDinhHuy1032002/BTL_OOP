#ifndef STACK_H
#define STACK_H
#endif

#pragma once
#include "Nhanvien.h"

struct Node {
	NhanVien data;
	Node *link;
};

class Stack {
	private:
		Node *top;
	public:
		Stack();
		~Stack();
		void push(NhanVien nv);
		NhanVien pop();
		NhanVien peek();
		bool isEmpty();
		int size();
		string toSaveFile();
		string toString();
		string toStringSearch();
		void sort(vector<string> *chucVu, int index, int direction);
		void search(Stack *temp, vector<string> *chucVu, int index);
		void deleteSearch(Stack *temp);
		void deleteNode(Stack *a, int position);
		void insertNode(NhanVien nv, vector<string> *chucVu, int index, int direction);
		bool CheckExitChucVu(string chucVu);
		void editDataChucVu(string chucVuTruoc, string chucVuSau);
};
