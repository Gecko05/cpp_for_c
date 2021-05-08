#include <iostream>
using namespace std;

class rational {
    public:
        rational(int n = 0) : a(n), q(1) {}
        rational(int i, int j) : a(i), q(j){}
        rational(double r) : q(BIG), a(r * BIG){}
        void print() const { cout << a << "/" << q; }
        operator double() { return static_cast<double>(a)/q; }
        friend ostream&
            operator<<(ostream& out, rational x);
        friend istream&
            operator>>(istream& in, rational& x);
    private:
        long a, q;
        enum { BIG = 100 };
};

inline int greatert(int i, int j)
{
    return (i > j ? i : j);
}

inline double greatert(double x, double y)
{
    return (x > y ? x : y);
}

inline rational greatert(rational w, rational z)
{
    return (w > z ? w : z);
}

ostream& operator<<(ostream& out, rational x)
{
    return (out << x.a << " / " << x.q << '\t');
}

istream& operator>>(istream& in, rational& x)
{
    return (in >> x.a >> x.q);
}

int main()
{
    int i = 10, j = 5;
    float x = 7.0;
    double y = 14.5;
    rational w(10), z(3.5), zmax;

    cout << "\ngreater(" << i << ", " << j << ") = "
         << greatert(i, j);
    cout << "\ngreater(" << x << ", " << y << ") = "
         << greatert(x, y);
    cout << "\ngreater(" << i << ", ";
    z.print();
    cout << ") = " << greatert(static_cast<rational>(i), z);
    zmax = greatert(w, z);
    cout << "\ngreater(";
    w.print();
    cout << ", ";
    z.print();
    cout << ") = ";
    zmax.print();
}