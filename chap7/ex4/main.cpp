#include <iostream>
using namespace std;

template<class TYPE>
void cycle(TYPE& a, TYPE& b, TYPE& c)
{
    // replace a's value by b's and b's by c's
    // and c's by a's
    TYPE d = a;
    a = b;
    b = c;
    c = d;
}

class spVal
{
    public:
        spVal(){
            m = 0;
            c = '0';
        }
        spVal(int a, char b)
        {
            m = a;
            c = b;
        }
        spVal(const spVal& val)
        {
            m = val.m;
            c = val.c;
        }
        spVal& operator=(const spVal& val)
        {
            m = val.m;
            c = val.c;
            return *this;
        }
        friend ostream& operator<<(ostream& output, spVal val);
    private:
        int m;
        char c;
};

ostream& operator<<(ostream& output, spVal val)
{
    return (output << val.m << " " << val.c << endl);
}

int main()
{
    int a = 2;
    int b = 3;
    int c = 5;
    cout << a << " " << b << " " << c << endl;
    cycle(a, b, c);
    cout << a << " " << b << " " << c << endl;
    spVal x(2,3);
    spVal y(3,4);
    spVal z(5,6);
    cycle(x,y,z);
}