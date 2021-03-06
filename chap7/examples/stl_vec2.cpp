// Sequence Containers - insert a vector into a deque

#include <iostream>

#include <deque>
#include <vector>

using namespace std;

int main()
{
    int data[5] = {6, 8, 7, 6, 5};
    vector<int> v(5, 6);    //5 element vector
    deque<int> d(data, data + 5);
    deque<int>::iterator p;
    cout << "\nDeque values" << endl;
    for (p = d.begin(); p != d.end(); ++p)
    {
        cout << *p << '\t';     //print: 6 8 7 6 5
    }
    cout << endl;
    d.insert(d.begin(), v.begin(), v.end());
    for (p = d.begin(); p != d.end(); p++)
    {
        cout << *p << '\t';     // print: 6 6 6 6 6 6 6 8 7 6 5
    }
}