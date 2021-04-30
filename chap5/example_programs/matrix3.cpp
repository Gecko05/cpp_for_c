// dynamic matrix type
#include <iostream>
#include "assert.h"

using namespace std;

class matrix{
    public:
        matrix(int c, int r);
        ~matrix();
        int ub1() const { return(c_size - 1); }
        int ub2() const { return(r_size - 1); }
        double& operator()(int i, int j);
        matrix& operator=(const matrix& m);
        matrix& operator+=(matrix& m);
    private:
        int c_size, r_size;
        double **p;
};

matrix::matrix(int c, int r): c_size(c), r_size(r)
{
    p = new double*[c];
    assert(p != 0);
    for (int i = 0; i < c; ++i)
    {
        p[i] = new double[r];
        assert(p[i] != 0);
    }
}

matrix::~matrix()
{
    for (int i = 0; i < c_size; ++i)
    {
        delete [] p[i];
    }
    delete [] p;
}

inline double& matrix::operator()(int i, int j)
{
    assert( i >= 0 && i < c_size &&
            j >= 0 && j < r_size);
    return p[i][j];
}

matrix& matrix::operator=(const matrix& m)
{
    assert(m.c_size == c_size && m.r_size == r_size);
    int i, j;

    for (i = 0; i < c_size; ++i)
    {
        for (j = 0; j < r_size; ++j)
        {
            p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator+=(matrix& m)
{
    assert(m.c_size == c_size && m.r_size == r_size);
    int i, j;

    for (i = 0; i < c_size; ++i)
    {
        for (j = 0; j < r_size; ++j)
        {
            p[i][j] += m.p[i][j];
        }
    }
    return *this;
}