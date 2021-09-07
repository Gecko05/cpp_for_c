class B {
public:
    virtual void foo(int);
    virtual void foo(double);
};

class D : public B {
public:
    void foo(int);
};

int main()
{
    D d;
    B b, *pb = &d;

    b.foo(9);
    b.foo(9.5);
    d.foo(9);     // D::foo(int)
    d.foo(9.5);   // D::foo(int)
    pb->foo(9);   // D::foo(int)
    pb->foo(9.5); // B::foo(double)
}