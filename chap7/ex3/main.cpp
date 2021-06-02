#include <iostream>
#include <math.h>
using namespace std;

#define CUBE(X) ((X) * (X) * (X))

template<class T>
T cube (T x)
{
    return x * x * x;
}

int main()
{
    cout << cube(sqrt(7)) << endl;
    cout << CUBE(sqrt(7)) << endl;
}