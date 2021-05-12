#ifndef __COMPLEX__H
#define __COMPLEX__H

#include <iostream>
using namespace std;

class complex {
    public:
        complex();
        complex(double r);
        void assign(double r, double i);
        void print();
        operator double();
        friend ostream& operator<<(ostream& out, complex x);
        complex operator-();
        complex operator=(complex c);
        friend complex operator+(complex a, complex b);
        friend complex operator*(complex a, complex b);
        friend complex operator-(complex a, complex b);
        friend complex operator+(complex a, double b);
        friend complex operator+(double b, complex a);
    private:
        double real, imag;
};

#endif // __COMPLEX__H