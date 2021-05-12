#include <iostream>
#include <math.h>
#include "complex.h"

complex::complex(double r)
{
    real = r;
    imag = 0;
}

complex::complex()
{
    real = 0;
    imag = 0;
}

void complex::assign(double r, double i)
{
    real = r;
    imag = i;
}

void complex::print()
{
    cout << real << " + " << imag << "i ";
}

complex::operator double()
{
    return (sqrt(real * real + imag * imag));
}

complex complex::operator-()
{
    complex r(0);
    r.assign(-(this->real), -(this->imag));
    return r;
}

ostream& operator<<(ostream& out, complex x)
{
    out << x.real << " + " << x.imag << "i ";
    return out;
}

complex operator+(complex a, complex b)
{
    complex r(0);
    r.real = a.real + b.real;
    r.imag = a.imag + b.imag;
    cout << "result adding" << r << endl;
    return r;
}

complex operator*(complex a, complex b)
{
    complex r(0);
    r.real = (a.real * a.real) - (a.imag * b.imag);
    r.imag = (a.real * a.imag) + (a.imag * b.real);
    return r;
}

complex operator-(complex a, complex b)
{
    complex r(0);
    r.real = a.real - b.real;
    r.imag = a.imag - b.imag;
    return r;
}

complex operator+(complex a, double b)
{
    complex r(b);
    r = a + r;
    return r;
}

complex operator+(double b, complex a)
{
    return (a + b);
}

complex complex::operator=(complex c)
{
    cout << "assigning" << endl;
    real = c.real;
    imag = c.imag;
    return c;
}