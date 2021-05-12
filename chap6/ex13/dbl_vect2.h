// A safe array type dbl_vect with [] overloaded

#include <iostream>
#include <assert.h>

using namespace std;

class dbl_vect {
    public:
        // constructors and destructor
        explicit dbl_vect(int n = 10);
        dbl_vect(const dbl_vect& v);
        dbl_vect(const double a[], int n);      // initialize by array
        ~dbl_vect() { delete []p; }
        // other member functions
        int ub() const { return (size - 1); }   // upper bound
        double& operator[](int i);              // range checked
        dbl_vect& operator=(const dbl_vect& v); // assignment
        dbl_vect operator+(const dbl_vect& v);
        double& iterate();
        friend void print(dbl_vect& a);
        friend class dbl_vect_iterator;
    private:
        double* p;                              // base pointer
        int size;                               // number of elements
};

dbl_vect::dbl_vect(int n) : size(n)
{
    assert(n > 0);
    p = new double[size];
    assert(p != 0);
}

dbl_vect::dbl_vect(const double a[], int n) : size(n)
{
    assert(n > 0);
    p = new double[size];
    assert(p != 0);
    for (int i = 0; i < size; ++i)
    {
        p[i] = a[i];
    }
}

dbl_vect::dbl_vect(const dbl_vect& v) : size(v.size)
{
    p = new double[size];
    assert(p != 0);
    for (int i = 0; i < size; ++i)
    {
        p[i] = v.p[i];
    }
}

// this overloaded operator can return a reference, so they can used 
// on either side of an assignment.
double& dbl_vect::operator[](int i)
{
    assert(i >= 0 && i < size);
    return p[i];
}

dbl_vect& dbl_vect::operator=(const dbl_vect& v)
{
    if (this != &v) {                   // do nothing if assigned to self
        assert(v.size == size);
        for (int i = 0; i < size; ++i)
        {
            p[i] = v.p[i];
        }
    }
    return *this;
}

dbl_vect dbl_vect::operator+(const dbl_vect& v)
{
    assert(size == v.size);
    dbl_vect sum(size);
    for (int i = 0; i < size; ++i)
    {
        sum.p[i] = p[i] + v.p[i];
    }
    return sum;
}

double& dbl_vect::iterate()
{
    static int i = 0;
    i = i % size;
    return p[i++];
}

void print(dbl_vect &a)
{
    for (int i = 0; i < a.size; i++)
    {
        cout << a.iterate() << " ";
    }
    cout << endl;
}

class dbl_vect_iterator
{
    public:
        dbl_vect_iterator(dbl_vect& v) : p(&v), position(0) { }
        double& iterate();
    private:
        dbl_vect *p;
        int position;
};

double& dbl_vect_iterator::iterate()
{
    return (*p)[position++];
}