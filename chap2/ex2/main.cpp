#include <iostream>
using namespace std;

int gcd(int m, int n, int q)
{
    for (int r = 0; n != 0;)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main(){
    int q;
    cout << "How many GCD? ";
    cin >> q;
    gcd(10, 4, q);
}