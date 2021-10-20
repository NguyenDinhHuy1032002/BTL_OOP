#include <iostream>
#include <iomanip> // Nhap nhieu gia tri trong 1 cau lenh
#include <string>
using namespace std;

struct Date{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

// Employee
class Employee{
	protected:
		string Name;
		string id;
		Date DoB;	// date of birth
		string PoB;	//place of birth
		int YearofWork;
		int Dayoff;
	public:
		long size;
		
		friend istream& operator >> (istream& Emp, Employee &el);
		friend ostream& operator << (ostream& Emp, Employee &el);
		int getYoW();
		int getDayoff();
		
		Employee();
		~Employee();
};

// Productor
class Productor : public Employee {
	private:
		float Money; // money for 1 product
		int NoP; // number of product
	public:
		friend istream& operator >> (istream& Pro, Employee &el);
		friend ostream& operator << (ostream& Pro, Employee &el);
		float SalaryPro();
};

// Officer
class Officer : public Employee {
	private:
		float BasicSalary;
		int NoW; // number of work day
	public:
		friend istream& operator >> (istream& Off, Employee &el);
		friend ostream& operator << (ostream& Off, Employee &el);
		float SalaryOff();
};

// Office
class Office {
	private:
		Productor *NVSX;
		Officer *NVVP;
	public:
		friend istream& operator >> (istream& is, Employee &el);
		friend ostream& operator << (ostream& os, Employee &el);
};

// Employee
istream& operator >> (istream& Emp, Employee &el)
{
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, el.Name);
	cout << "Enter ID: ";
	getline(cin, el.id);
	cout << "Enter day of birth: ";
	cin.ignore();
	cin >> el.DoB.day >> el.DoB.month >> el.DoB.year;
	cout << "Enter place of birth: ";
	cin >> el.PoB;
	cout << "Enter year of work: ";
	cin >> el.YearofWork;
	cout << "Enter day off: ";
	cin >> el.Dayoff;
	return Emp;
}

ostream& operator << (ostream& Emp, Employee &el){
	cout << el.Name  << setw(10) << endl;
	cout << el.id << setw(10) << endl;
	cout << el.DoB.day << "/" << el.DoB.month << "/" << el.DoB.year << setw(10) << endl;
	cout << el.PoB << setw(10) << endl;
	cout << el.YearofWork << setw(10) << endl;
	cout << el.Dayoff << setw(10) << endl;
	return Emp;
}

int Employee::getYoW() {
	return YearofWork;
}

int Employee::getDayoff() {
	return Dayoff;
}

// Productor

istream& operator >> (istream& Pro, Employee &el) {
	
	
}







