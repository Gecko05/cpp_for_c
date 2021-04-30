#include <iostream>
using namespace std;

class rational {
    public:
        friend ostream&
            operator<<(ostream& out, rational x);
        friend istream&
            operator>>(istream& in, rational& x);
    private:
        long a, q;
};

ostream& operator<<(ostream& out, rational x)
{
    return (out << x.a << " / " << x.q << '\t');
}

istream& operator>>(istream& in, rational& x)
{
    return (in >> x.a >> x.q);
}