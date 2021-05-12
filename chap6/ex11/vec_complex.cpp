#include "complex.h"
#include "assert.h"

class vec_complex{
    public:
        vec_complex(int sz);
        vec_complex(const double rl[], int sz);
        vec_complex(const double rl[], const double im[], int sz);
        friend complex operator*(vec_complex a, vec_complex b);
        friend vec_complex operator+(vec_complex a, vec_complex b);
    private:
        int n;
        complex *p;
};

vec_complex::vec_complex(int sz)
{
    if (sz == 0)
    {
        return;
    }
    p = new complex[sz];
    assert(p != 0);
    n = sz;
}

vec_complex::vec_complex(const double rl[], int sz)
{
    if (sz == 0)
    {
        return;
    }
    p = new complex[sz];
    assert(p != 0);
    n = sz;
    for (int i = 0; i < n; i++)
    {
        p->assign(rl[i], 0);
    }
}

vec_complex::vec_complex(const double rl[], const double im[], int sz)
{
    if (sz == 0)
    {
        return;
    }
    p = new complex[sz];
    assert(p != 0);
    n = sz;
    for (int i = 0; i < n; i++)
    {
        p[i].assign(rl[i], im[i]);
    }
}

complex operator*(vec_complex a, vec_complex b)
{
    complex dot_prod(0);
    if (a.n != b.n)
    {
        return 0;
    }
    cout << "Calculating dot product" << endl;
    cout << a.n << endl;
    for (int i = 0; i < a.n; i++)
    {
        cout << a.p[i] << " " << b.p[i] << endl;
        cout << (a.p[i] * b.p[i]) << endl;
        dot_prod = dot_prod + (a.p[i] * b.p[i]);
    }
    cout << dot_prod << endl;
    return dot_prod;
}

vec_complex operator+(vec_complex a, vec_complex b)
{
    if (a.n != b.n)
    {
        return a;
    }
    vec_complex vec_res(a.n);
    for (int i = 0; i < a.n; i++)
    {
        vec_res.p[0] = a.p[i] + b.p[i];
    }
    return vec_res;
}

int main()
{
    const double r1[3] = {1,2,3};
    const double im1[3] = {4,5,6};

    const double r2[3] = {1,2,3};
    const double im2[3] = {5,6,7};
    vec_complex vec1(r1, im1, 3);
    vec_complex vec2(r2, im2, 3);
    complex dot_product = vec1 * vec2;
    cout << dot_product << endl;

    cout << "Hello honey" << endl;
}