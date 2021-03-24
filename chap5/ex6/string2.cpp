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
        int my_string::strcmp(const my_string& s1);
        void my_string::strrev();
        void my_string::print(int n);
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

// strcmp is negative if s < s1,
//      is 0 if s == s1,
//      and is positive if s > s1
//      where s is the implicit argument

int my_string::strcmp(const my_string& s1)
{
    for (int i = 0; i < this->len ; i++)
    {
        if (this->s[i] < s1.s[i]){
            return -1;
        }
        else if (this->s[i] > s1.s[i]){
            return 1;
        }
    }
    return 0;
}

// strrev reverses the my_string
void my_string::strrev(){
    char* sr = new char[len];
    memcpy(sr, this->s, this->len);
    for (int i = 0; i < len; i++)
    {
        this->s[len-i-1] = sr[i];
    }
    delete []sr;
}

// print overloaded to print the first n characters
void my_string::print(int n){
    for (int i = 0; (i < n) && (i < len); i++)
    {
        cout << this->s[i];
    }
}