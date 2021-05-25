#include "vect_it.h"
#include <iostream>

using namespace std;

int main()
{
    vector<double> v(5);
    vector<double>::iterator p;
    int i = 0;

    for (p = v.begin(); p != v.end(); ++p)
    {
        *p = 1.5 + i++;
    }
    do {
        --p;
        cout << *p << " , ";
    } while (p != v.begin());
    cout << endl;
}