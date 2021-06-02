// template stack implementation

#include <iostream>
#include <assert.h>

using namespace std;

template <class TYPE, int size>
class stack{
    public:
        explicit stack()
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
            return top == EMPTY;
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

int main()
{
    stack<int, 100> s1;
    for (int i = 0; i < 10; i++)
    {
        if (s1.full())
        {
            cout << "error, full stack" << endl;
        }
        else
        {
            s1.push(i);
        }
    }
}