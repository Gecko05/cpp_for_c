#include <iostream>
#include "assert.h"
#include "dbl_vect.h"

class multi_v {
    public:
        multi_v(int i): a(i), b(i), c(i), size(i) {}
        void assign(int ind, int i, int j, int k);
        void retrieve(int ind, int& i, int& j, int& k);
        void print(int ind);
        int ub() const { return (size - 1); }
    private:
        dbl_vect a, b, c;
        int size;
};