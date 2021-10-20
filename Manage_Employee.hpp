#include <iostream>
using namespace std;

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

class Employee {
    private:
        string name;
        string id;
        Date DoB; // date of birth
        string PoB; //place of birth
        int YearofWork;
        int Dayoff;
    public:
        long size;
        void InputEmp();
        void OutputEmp();
        int getYoW();
        int getDayoff();
};

class Productor : public Employee {
    private: 
        float Money; // money for 1 product
        int NoP; // number of product;
    public:
        void InputPro();
        void OutputPro();
        float SalaryPro();
};

class Officer : public Employee {
    private:
        float BasicSalary;
        int NoW; // number of working days
    public:
        void InputOff();
        void OutputOff();
        float SalaryOff();
};

class Office {
    private:
        Productor *NVSX;
        Officer *NVVP;
    public:
        void Input();
        void Output();
};