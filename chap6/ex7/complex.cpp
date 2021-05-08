#include <iostream>
#include <math.h>
using namespace std;

class complex {
    public:
        complex(double r);
        void assign(double r, double i);
        void print();
        operator double();
        friend ostream& operator<<(ostream& out, complex x);
        complex operator-();
    private:
        double real, imag;
};

complex::complex(double r)
{
    real = r;
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

int main(int argc, char *arv[])
{
    complex cm1(5);
    complex cm2(0);
    cm2.assign(3, 5);
    cout << cm2 << endl;
    cout << (-cm2) << endl;
}