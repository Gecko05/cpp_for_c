#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

void get_roots(double &root1, double &root2)
{
    int a, b, c;
    cin >> a >> b >> c;
    double discr = static_cast<double>((b * b) - (4 * a * c));
    double sq_disc;
    if ((discr > 0) && (sq_disc = sqrt(discr))){
        root1 = (-b + sq_disc) / (2 * a);
        root2 = (-b - sq_disc) / (2 * a);
    }
    else if (discr < 0){
        complex<double> root1, root2;
        complex<double> csq_disc;
        csq_disc = sqrt(complex<double>(discr, 0));
        root1 = (complex<double>(-b,0) + csq_disc) / complex<double>(2 * a, 0);
        root2 = (complex<double>(-b,0) - csq_disc) / complex<double>(2 * a, 0);   
    }
    else{
        root1 = root2 = -b / (2 * a);
    }

}

int main(int argc, char *argv[])
{
    double root1 = 0.0 , root2 = 0.0;
    get_roots(root1, root2);
    cout << "Root1: " << root1 << " Root2: " << root2 << endl;
}