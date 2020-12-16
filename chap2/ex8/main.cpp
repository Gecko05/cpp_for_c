#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    cout << "Bool: " << sizeof(bool) << endl;
    cout << "Short: " << sizeof(short) << endl;
    cout << "Char: " << sizeof(char) << endl;
    cout << "Int: " << sizeof(int) << endl;
    cout << "Long: " << sizeof(long) << endl;
    cout << "Double: " << sizeof(double) << endl;
    cout << "Long double: " << sizeof(long double) << endl;
    enum bounds {lib = 1, ub = 511};
    enum suit {clubs, diamonds, hearts, spades};
    cout << "Bounds: " << sizeof(bounds) << endl;
    cout << "Suit: " << sizeof(suit) << endl;
}