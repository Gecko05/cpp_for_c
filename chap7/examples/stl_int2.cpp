#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

double integrate(gen g, int n, double& diff)
{
    vector<double> fx(n), smn(n), lg(n);
    double s, l;

    generate(fx.begin(), fx.end(), g);
    for (int i = 0; i < n - 1; ++i)
    {
        if (fx[i] > fx[i + 1])
        {
            sm[i] = fx[i + 1];
            lg[i] = fx[i];
        }
        else
        {
            sm[i] = fx[i];
            lg[i] = fx[i + 1];
        }
    }
    s = accumulate(sm.begin(), sm.end(), 0.0)/n ;
    l = accumulate(lg.begin(), lg.end(), 0.0)/n ;
    diff = l - s;
    return (s + 1) / 2;
}