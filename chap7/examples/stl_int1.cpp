// Simple integration routine for x*x over (0, 1)
// The function is represented in class ge

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

class gen {
    public:
        gen(double x_zero, double increment) : x(x_zero),
        incr(increment) { }
        double operator()() { x += incr; return x*x; }
    private:
        double x, incr;
};

double integrate(gen g, int n) // integrate on (0, 1)
{
    vector<double> fx(n);

    generate(fx.begin(), fx.end(), g);
    return(accumulate(fx.begin(), fx.end(), 0.0) / n);
}

int main()
{
    const int n = 10000;
    
    gen g(0.0, 1.0/n);
    cout << "integration program x**2" << endl;
    cout << integrate(g, n) << endl;
}