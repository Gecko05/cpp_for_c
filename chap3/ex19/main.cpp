#include <iostream>

double plot(double y[], double fcn(double), double x0,
            double x1, double incr)
{
    double xdelta = x1 - x0;
    if (xdelta <= 0)
    {
        return 0;
    }
    for (double d = x0,i = 0; d < x1; i++, d+=incr)
    {
        y[static_cast<int>(i)] = fcn(d);
    }
    return 1;
}

double dada(double x)
{
    return x * 1;
}

int main(){
    double res[1000];
    plot(res, dada, 0, 1.0, 0.001);
    for (int i =0; i < 1000; i++)
    {
        std::cout << res[i] << std::endl;
    }
    
}