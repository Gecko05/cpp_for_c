// virtual function selection
#include <iostream>

using namespace std;

class B {
public:
    int i;
    virtual void print_i() const {
        cout << i << " inside B" << endl;
    }
};

class D : public B {
public:
    //virtual as well
    void print_i() const {
        cout << i << " inside D" << endl;
    };
};

int main()
{
    B b;
    B* pb = &b; // points at a B object
    D f;

    f.i = 1 + (b.i = 1);
    pb->print_i(); //call B::print_i()
    pb = &f; // points at a D object
    pb->print_i(); // call D::print_i()
}