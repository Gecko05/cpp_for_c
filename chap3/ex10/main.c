// Print command-line arguments rightmost first
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int c = 0;
    for (--argc; argc >= 0; --argc)
    {
        cout << c++ << " " << argv[argc] << endl;
    }
}