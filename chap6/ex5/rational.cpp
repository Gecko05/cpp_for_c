#include <iostream>

using namespace std;

class rational{
    public:
        rational(int div, int quo);
        void print();
        friend bool operator ==(rational a, rational b);
    private:
        int a;
        int q;
};

int gcd(int x, int y)
{
    if (y > x)
    {
        return gcd(y, x);
    }
    else if (x % y == 0)
    {
        return y;
    }
    else
    {
        return gcd(y, x % y);
    }
}

rational::rational(int div, int quo)
{
    int divisor = gcd(div, quo);
    a = div/divisor;
    q = quo/divisor;

}

void rational::print()
{
    cout << a << "/" << q << endl;
}

bool operator ==(rational a, rational b)
{
    if ((a.a == b.a) && (a.q == b.q))
    {
        cout << "Equal" << endl;
        return true;
    }
    cout << "Not Equal" << endl;
    return false;
}

int main()
{
    rational r1(68, 136);
    rational r2(1, 2);
    cout << gcd(68, 136) << endl;
    if (r1 == r2)
    {
        cout << "Success" << endl;
    }
    r1.print();
}