/* Compute a table of cubes. */
#include <iostream>

const int N = 15;
const double MAX = 3.5;

int main()
{
    double cube(double x);

    std::cout << "\n\nINTEGERS\n";
    for (int i = 1; i <= N; i++){
        std::cout << "cube(" << i << ") = " << cube(i) << std::endl;
    }
    std::cout << "\n\nREALS\n";
    for (double x = 1; x <= MAX; x += 0.3){
        std::cout << "cube(" << x << ") = " << cube(x) << std::endl;
    }
}

double cube(double x)
{
    return (x * x * x);
}

