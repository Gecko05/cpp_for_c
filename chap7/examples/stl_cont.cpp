// Using the list container
#include <iostream>
#include <list>
#include <numeric>

using namespace std;

void print( list<double> &lst)
{
    // using an iterator to traverse lst
    list<double>::iterator p;

    for (p = lst.begin(); p != lst.end(); ++p)
    {
        cout << *p << '\t';
    }
    cout << endl;
}

int main()
{
    double w[4] = { 0.9, 0.8, 88, -99.99 };
    list<double> z;
    for (int i = 0; i < 4; ++i)
    {
        z.push_front(w[i]);
    }
    print(z);
    z.sort();
    print(z);
    cout << "sum is "
         << accumulate(z.begin(), z.end(), 0.0) << endl;
}