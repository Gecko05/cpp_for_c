// Program to convert from Celsius to Fahrenheit
#include <iostream>
using namespace std;

int cel_to_fah(int cel)
{
    int fah = (cel * 1.8) + 32;
    return fah;
}

int main(int argc, char *argv[])
{
    cout << cel_to_fah(30) << endl;
}