// Polynomials with overloaded arithmetic operators
#include <iostream>
using namespace std;

class polynomial {
    public:
        polynomial();
        polynomial(const polynomial& p);
        polynomial(int size, double coef[], int expon[]);
        ~polynomial() { release(); }
        void print() const;
        double operator()(double x) const; // evaluate P(x)
        polynomial& operator=(const polynomial& a);
        friend polynomial& operator+(const polynomial& a,
                                     const polynomial& b);
        friend polynomial& operator-(const polynomial& a,
                                     const polynomial& b);
        friend polynomial& operator*(const polynomial& a,
                                     const polynomial& b);
        friend polynomial& operator/(const polynomial& a,
                                     const polynomial& b);
        friend polynomial& operator-(const polynomial& a);
        friend polynomial& operator+=(polynomial& a,
                                     const polynomial& b);
        friend bool operator==(const polynomial& a,
                               const polynomial& b);
        friend bool operator!=(const polynomial& a,
                               const polynomial& b);
    private:
        term* h;
        int degree;
        void prepend(term* t);
        void add_term(term*& a, term*& b);
        void release();
        void rest_of(term* rest);
        void reverse();              
};

polynomial& polynomial::operator=(const polynomial& a)
{
    if (h != a.h)       //avoid a = a case
    {
        release();  // garbage collect old value
        polynomial* temp = new polynomial(a);
        h = temp->h;
        degree = temp->degree;
    }
    return *this;
}
