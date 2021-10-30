#include <iostream>
#include <iomanip>
#include <string>
#include "Manage_Employee.hpp"
using namespace std;

//Employee

void Employee::InputEmp() {
    cout << "Enter name: ";
    getline(cin, name);
    getline(cin, id);
    cout << "Enter ID: ";
    cin.ignore();
    cout << "Enter place of birth: ";
    getline(cin, PoB);
    cin.ignore();
    cout << "Enter day of birth (dd/mm/yy): ";
    cin >> DoB.day >> DoB.month >> DoB.year;
    cout << "Enter year of work: ";
    cin >> YearofWork;
    cout << "Enter day off: ";
    cin >> Dayoff;
}

void Employee::OutputEmp() {
    cout << setw(10) << name << setw(10) << id << setw(10);
    cout << DoB.day << "/" << DoB.month << "/" << DoB.year << setw(10);
    cout << PoB << setw(10) << YearofWork << setw(10) << Dayoff << setw(10);
}

int Employee::getYoW() {
    return YearofWork;
}

int Employee::getDayoff() {
    return Dayoff;
}

//Productor

void Productor::InputPro() {
    InputEmp();
    cout << "Enter money for 1 product: ";
    cin >> Money;
    cout << "Enter the number of product: ";
    cin >> NoP;
}

void Productor::OutputPro() {
    OutputEmp();
    cout << Money << setw(10) << NoP << setw(10);
}

float Productor::SalaryPro() {
    float slr = 0;
    slr = Money*NoP - getDayoff()*Money*NoP;
    if(getYoW() >= 1 && getYoW() <= 4){
        slr += 4500000;  
    }
    if(getYoW() <= 10){
        slr += 8000000; 
    }
    else{
        slr += 15000000;
    }
    return slr;
}

//Officer

void Officer::InputOff() {
    InputEmp();
    cout << "Enter basic salary: ";
    cin >> BasicSalary;
    cout << "Enter the number of working days: ";
    cin >> NoW;
}

void Officer::OutputOff() {
    OutputEmp();
    cout << BasicSalary << setw(10) << NoW << setw(10);
}

float Officer::SalaryOff() {
    float slr = 0;
    slr = BasicSalary*NoW*(30 - getDayoff());
    if(getYoW() >= 1 && getYoW() <= 4){
        slr += 4500000;  
    }
    if(getYoW() <= 10){
        slr += 8000000; 
    }
    else{
        slr += 150000000;
    }
    return slr;
}

//Office

void Office::Input() {
    int n;
    //Productor in Office
    cout << "Enter the number of productor: ";
    cin >> n;
    NVSX = new Productor[n];
    NVSX->size = n;
    for(int i=0; i<n; i++) {
        NVSX[i].InputPro();
    }
    cout << "\n---------------------------------------------\n";
    //Officer in Office
    int m;
    cout << "Enter the number of officer: ";
    cin >> m;
    NVVP = new Officer[m];
    NVVP->size = m;
    for(int i=0; i<m; i++) {
        NVVP[i].InputOff();
    }
}

 int main() {
    Office cty;
    cty.Input();
}