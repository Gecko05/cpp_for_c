#include <iostream>

using namespace std;

double& dbl_vect::iterate()
{
    static int i = 0;
    i = i % size;
    return p[i++];
}