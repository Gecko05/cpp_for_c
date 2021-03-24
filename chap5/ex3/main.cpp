#include <iostream>

// Constructors and destructors invoked

using namespace std;

class A {
    public:
        A() : xx(0) { cout << "A() called" << endl;}
        A(int n) : xx(n)
            { cout << "A(int " << n << ") called" << endl; }
        A(double y) : xx(y + 0.5)
            { cout << "A(fl " << y << ") called" << endl; }
        ~A()
            { cout << "~A() with A::xx = " << xx << endl; }
    private:
        int xx;
};

int main()
{
    cout << "enter main\n";
    int x = 14;
    float y = 17.3;
    A z(11), zz(11.5), zzz(0);
    A d[5];

    cout << "\nOBJECT ALLOCATION LAYOUT\n";
    cout << "\nx is at " << &x;
    cout << "\ny is at " << &y;
    cout << "\nz is at " << &z;
    cout << "\nzz is at " << &zz;
    cout << "\nzzz is at " << &zzz;
    cout << "\n___________________________\n";
    zzz = A(x);
    zzz = A(y);
    cout << "exit main" << endl;
}