#include "complex.h"
#include "assert.h"

class vec_complex{
    public:
        vec_complex(int sz);
        vec_complex(double rl[], int sz);
        vec_complex(double rl[], double im[], int sz);
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

vec_complex::vec_complex(double rl[], int sz)
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

vec_complex::vec_complex(double rl[], double im[], int sz)
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
        p->assign(rl[i], im[i]);
    }
}