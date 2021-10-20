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
		
		friend istream& operator >> (istream& is, Employee &el);
		friend ostream& operator << (ostream& is, Employee &el);
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
		friend istream& operator >> (istream& is, Productor &el);
		friend ostream& operator << (ostream& is, Productor &el);
		float SalaryPro();
};

// Officer
class Officer : public Employee {
	private:
		float BasicSalary;
		int NoW; // number of work day
	public:
		friend istream& operator >> (istream& is, Officer &el);
		friend ostream& operator << (ostream& is, Officer &el);
		float SalaryOff();
};

// Office
class Office {
	private:
		Productor *NVSX;
		Officer *NVVP;
	public:
		friend istream& operator >> (istream& is, Office &el);
		friend ostream& operator << (ostream& os, Office &el);
};

// Employee
istream& operator >> (istream& is, Employee &el)
{
	cout << "Enter name: ";
	cin.ignore();
	is.getline(el.Name);
	cout << "Enter ID: ";
	is.getline(el.id);
	cout << "Enter day of birth: ";
	cin.ignore();
	is >> el.DoB.day >> el.DoB.month >> el.DoB.year;
	cout << "Enter place of birth: ";
	is >> el.PoB;
	cout << "Enter year of work: ";
	is >> el.YearofWork;
	cout << "Enter day off: ";
	is >> el.Dayoff;
	return is;
}

ostream& operator << (ostream& os, Employee &el){
	cout <<"Name: " << el.Name  << setw(10) << endl;
	cout <<"ID: " << el.id << setw(10) << endl;
	cout <<"dd/mm/yy: " << el.DoB.day << "/" << el.DoB.month << "/" << el.DoB.year << setw(10) << endl;
	cout <<"Place of birth: " << el.PoB << setw(10) << endl;
	cout <<"Year of Work: " << el.YearofWork << setw(10) << endl;
	cout <<"Day off: " << el.Dayoff << setw(10) << endl;
	return os;
}

int Employee::getYoW() {
	return YearofWork;
}

int Employee::getDayoff() {
	return Dayoff;
}

// Productor

istream& operator >> (istream& is, Productor &el) {
	Employee *p = &el;
	is >> *p;
	cout << "Enter money for 1 product: ";
	is >> el.Money;
	cout << "Enter the number of product: ";
	is >> el.NoP;
	return is;
}

ostream& operator >> (ostream& os, Productor &el) {
	Employee *p = &el;
	os << *p;
	os << "Money: " << el.Money <<setw(10) << endl;
	os << "Number of product: " << el.NoP <<setw(10) << endl;
	return os;
}

float Productor::SalaryPro() {
	float slr = 0;
	slr = Money*NoP - getDayoff()*Money*NoP;
	if (getYoW() >= 1 && getYoW <=4) {
		slr += 4500000;
	}
	if (getYoW() <= 10) {
		slr += 8000000;
	}
	else {
		slr += 15000000;
	}
	return slr;
}

// Officer

istream& operator >> (istream& is, Officer &el) {
	Employee *o = &el;
	is >> *o;
	cout << "Enter basic salary: ";
	is >> el.BasicSalary;
	cout << "Enter the number of working days: ";
	is >> el.NoW;
	return is;
}

ostream& operator >> (ostream& os, Officer &el) {
	Employee *o = &el;
	os << *o;
	os << "Basic Salary: " << el.BasicSalary << setw(10) << endl;
	os << "Number of working days: " << el.NoW << setw(10) <<endl;
	return os;
}

float Officer::SalaryOff() {
	float slr = 0;
	slr = BasicSalary*NoW*(30 - getDayoff());
	if (getYoW() >= 1 && getYoW() <= 4){
		slr += 4500000;
	}
	if (getYoW() <= 10){
		slr += 8000000;
	}
	else {
		slr += 15000000;
	}
	return slr;
}

// Office

istream& operator >> (istream& is, Office &el) {
	int n;
	// Productor in Office
	cout << "Enter the number of productor: ";
	is >> n;
	NVSX = new Productor[n];
	NVSX->size = n;
	for (int i = 0; i < n; i++) {
		
	}
}














