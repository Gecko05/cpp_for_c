#include <iostream>

#include <vector>
#include <iterator>

using namespace std;

// Use of istream_iterator and ostream_iterator

int main()
{
    vector<int> d(5);
    int i, sum;
    istream_iterator<int> in(cin);
    ostream_iterator<int> out(cout, "\t");
    cout << "enter 5 numbers" << endl;
    sum = d[0] = *in;       //input first value
    for (i = 1; i < 5; ++i)
    {
        d[i] = *++in;       //input consecutive values
        sum += d[i];
    }
    for (i = 0; i < 5; ++i)
    {
        *out = d[i];        //output consecutive values
    }
    cout << " sum = " << sum << endl;
}