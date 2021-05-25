// Simple STL vector program
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(100); // 100 is the vector's size

    for (int i = 0; i < 100; i++)
    {
        v[i] = i;
    }
    for (vector<int>::iterator p = v.begin(); p != v.end(); p++)
    {
        cout << *p << '\t';
    }
}