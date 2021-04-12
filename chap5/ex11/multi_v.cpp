#include "multi_v.h"

using namespace std;

void multi_v::assign(int ind, int i, int j, int k)
{
    a.element(ind) = i;
    b.element(ind) = j;
    c.element(ind) = k;
}

void multi_v::retrieve(int ind, int& i, int& j, int& k)
{
    i = a.element(ind);
    j = b.element(ind);
    k = c.element(ind);
}

void multi_v::print(int ind)
{
    cout << a.element(ind)
         << b.element(ind)
         << c.element(ind) << endl;
}