#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    for (int r = 0; n != 0;)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}