// An implementation of dynamically allocated strings
#include <iostream>
#include <assert.h>

using namespace std;

class my_string {
    public:
        my_string(): len()
        {
            s = new char [1];
            assert(s != 0);
            s[0] = 0;
        }
        my_string(const my_string& str); // copy constructor
        my_string(const char* p);
        ~my_string() {
            delete []s;
        }
        void assign(const my_string& str);
        void print() const{
            cout << s << endl;
        }
        void concat(const my_string& a, const my_string& b);
    private:
        char* s;
        int len;
};

my_string::my_string(const char* p)
{
    len = strlen(p);
    s = new char[len + 1];
    assert(s != 0);
    strcpy(s, p);
}

my_string::my_string(const my_string& str): len(str.len)
{
    s = new char[len + 1];
    assert(s != 0);
    strcpy(s, str.s);
}

void my_string::assign(const my_string& str)
{
    if (this == &str) // a = a; do nothing
        return;
    delete []s;
    len = str.len;
    s = new char[len + 1];
    assert(s != 0);
    strcpy(s, str.s);
}

void my_string::concat(const my_string& a, const my_string& b)
{
    char* temp = new char[a.len + b.len + 1];
    
    len = a.len + b.len;
    strcpy(temp, a.s);
    strcat(temp, b.s);
    delete []s;
    s = new char[len + 1];
    assert(s != 0);
    strcpy(s, temp);
}