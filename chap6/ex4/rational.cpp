#include <iostream>

using namespace std;

class rational{
    public:
        rational(int div, int quo);
        void print();
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

int main()
{
    rational r1(68, 136);
    cout << gcd(68, 136) << endl;
    r1.print();
}