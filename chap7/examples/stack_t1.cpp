// template stack implementation

#include <iostream>

using namespace std;

template <class TYPE>
class stack{
    public:
        explicit stack(int size = 100)
            : max_len(size), top(EMPTY), s(new TYPE[size])
            {
                assert(s != 0);
            }
        ~stack()
        {
            delete []s;
        }
        void reset(){
            top = EMPTY;
        }
        void push(TYPE c)
        {
            s[++top] = c;
        }
        TYPE pop()
        {
            return s[top--];
        }
        TYPE top_of()const
        {
            return s[top];
        }
        bool empty() const
        {
            return return top == EMPTY;
        }
        bool full() const
        {
            return top == max_len - 1;
        }
    private:
        enum { EMPTY = -1 };
        TYPE* s;
        int max_len;
        int top;        
};

// Reversing an array of char* represented strings

void reverse(char* str[], int n)
{
    stack<char*> stk(n);
    int i;

    for (i = 0; i < n; i++)
    {
        stk.push(str[i]);
    }
    for (i = 0; i < n; i++)
    {
        str[i] = stk.pop();
    }
}

// Initializing stack of complex numbers from an array

void init(complex c[], stack<complex>& stk, int n)
{
    for (int i = 0; i < n; ++i)
    {
        stk.push(c[i]);
    }
}