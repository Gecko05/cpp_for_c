#include <iostream>
using namespace std;

int foo(int i)
{
    return (i * 5);
}

int goo(int i); // imported from file A.c

int main(){
    cout << "foo(5) = " << foo(5) << endl;
    cout << "goo(5) = " << goo(5) << endl;
}
