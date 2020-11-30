#include <iostream>
#include <string>

using namespace std;

class person{
    public:
        person(string nm, int bd, string ad)
        {
            this->name = nm;
            this->birthdate = bd;
            this->address = ad;
        }
        void print(void){
            cout << "Person " << name << endl;
            cout << birthdate << " " << address << endl;
        }
    private:
        string name;
        int birthdate;
        string address;
};

class student : public person {
    public:
        student(string nm, int bd, string ad, string sch) : person(nm, bd, ad){
            this->school = sch; 
        }
        void print(void);
    private:
        string school;
};

void student::print()
{
    person::print();
    cout << "School: " << this->school << endl;
}

int main(int argc, char *argv[])
{
    person mimi = person("Alejandra", 102030, "Av. Universidad");
    student memi = student("Akira", 103020, "Okinawa Miyagi San", "Lolitas Academy");
    mimi.print();
    memi.print();
}