#include <iostream>
#include <string>

using namespace std;

class person{
    public:
       person(const string nm, int bd, const string ad){
           name = nm;
           birthdate = bd;
           address = ad;
       }
       void print(void){
           cout << "Person: " << name << " Birthdate: " << birthdate \
           << " Address: " << address << endl;
       }
    private:
        string name;
        int birthdate;
        string address;
};

class student: public person {
    public:
        student(string nm, int bd, string ad, string sc);
        void print(void){
            person::print();
            cout << "School: " << school << endl;
        }
    private:
        string school;
};

student::student(string nm, int bd, string ad, string sc) : \
person(nm, bd, ad){
    school = sc;
}


int main(int argc, char *arv[])
{
    person Ness = person("Ness", 100690, "Onett 32");
    Ness.print();
    student Paula = student("Paula", 110189, "Twoson", "Kindergarten");
    Paula.print();
}