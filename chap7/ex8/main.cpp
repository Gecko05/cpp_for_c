#include "vect_it.h"
#include <iostream>

using namespace std;
char chars[3] = {'a','b','c'};
int ints[3] = {1,2,3};

int main(int argc, char *argv[])
{
    cout << "Hi, buddy" << endl;
    vector<int> my_ints(ints, 3);
    vector<char> my_chars(chars, 3);

    my_ints.print();
    my_chars.print();

    my_ints.swap(my_chars);
    my_ints.print();
    my_chars.print();

    my_ints.swap(my_chars);
    my_ints.print();
    my_chars.print();
    return 0;
}