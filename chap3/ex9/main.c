// Print command-line arguments rightmost first
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    for (--argc; argc >= 0; --argc)
    {
        cout << argv[argc] << endl;
    }
}