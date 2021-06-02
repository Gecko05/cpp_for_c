// template stack implementation

#include <iostream>
#include <assert.h>

using namespace std;

template <class TYPE>
class stack{
    public:
        explicit stack()
            : top(EMPTY), s(new TYPE[max_size])
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
            return top == max_size - 1;
        }
    private:
        enum { EMPTY = -1 };
        TYPE* s;
        const int max_size = 100;
        int top;        
};

int main()
{
    stack<int> s1;
    for (int i = 0; i < 100; i++)
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