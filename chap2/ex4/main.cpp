#include <iostream>
#include <cmath>

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
        cout << "Error: Roots are complex" << endl;
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