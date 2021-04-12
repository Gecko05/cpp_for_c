#include <iostream>
#include <assert.h>

using namespace std;

// Implementation of a safe array type dbl_vect
class dbl_vect {
    public:
        explicit dbl_vect(int n = 10);
        dbl_vect(const dbl_vect* d, int sz);
        ~dbl_vect() { delete []p; }
        double& element(int i);     // access p[i]
        int ub() const { return (size - 1); }
        void print() const;
        double sumelem();
        void add(const dbl_vect& v1, const dbl_vect& v2);
    private:
        double* p;
        int size;
};

dbl_vect::dbl_vect(int n) : size(n)
{
    assert(n > 0);
    p = new double[size];
    assert(p != 0);
}

dbl_vect::dbl_vect(const dbl_vect* d, int sz)
{
    assert(n > 0);
    p = new double[sz];
    assert(p != 0);
    memcpy(p, d->p, sz);
}


double& dbl_vect::element(int i)
{
    assert (i >= 0 && i < size);
    return p[i];
}

double dbl_vect::sumelem()
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += p[i];
    }
    return sum;
}

void dbl_vect::print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
}

void dbl_vect::add(const dbl_vect& v1, const dbl_vect& v2)
{
    int i = 0;
    int max_size = v1.size;
    if (v2.size > max_size)
    {
        max_size = v2.size;
    }
    assert(max_size > 0);
    size = max_size;
    cout << max_size << endl;
    delete []p;
    p = new double[max_size];
    assert(p != 0);
    while (i < max_size)
    {
        double sum = 0;
        if (i < v1.size)
        {
            sum += v1.p[i];
        }
        if (i < v2.size)
        {
            sum += v2.p[i];
        }
        p[i] = sum;
        i++;
    }
}