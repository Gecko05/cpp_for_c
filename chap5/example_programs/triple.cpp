// Overloading the structure pointer operator

#include <iostream>
using namespace std;

class triple {
    public:
        triple(int a, int b, int c)
        {
            i = a;
            j = b;
            k = c;
        }
        void print()
        {
            cout << "\ni = " << i << " , j ="
                             << j << ", k = " << k; 
        }
    private:
        int i, j, k;
};

triple unauthor(0, 0, 0);

class t_ptr {
    public:
        t_ptr(bool f, triple* p)
        {
            access = f;
            ptr = p;
        }
        triple* operator->() ;
    private:
        bool access;
        triple* ptr;
};

triple* t_ptr::operator->()
{
    if (access)
    {
        return ptr;
    }
    else {
        cout << "\nunauthorized access";
        return &unauthor;
    }
}

int main()
{
    triple a(1, 2, 3), b(4, 5, 6);
    t_ptr ta(false, &a), tb(true, &b);

    ta->print(); // access denied
    tb->print(); // access granted
}