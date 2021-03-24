#include <iostream>
#include <assert.h>
class ch_stack {
    public:
        explicit ch_stack(int size): max_len(size), top(EMPTY)
        { assert(size > 0); s = new char[size]; assert(s != 0); }
        ch_stack(): max_len(100), top(EMPTY)
        {s = new char[10]; assert(s != 0);}
        explicit ch_stack(const char* c);
        void reset() { top = EMPTY; }
        void push(char c) { s[++top] = c; }
        char pop() { return s[top--]; }
        char top_of() const { return s[top]; }
        bool empty() const { return (top == EMPTY); }
        bool full() const { return (top == max_len - 1); }
        void print() {
            std::cout << "Stack: " << std::endl;
            for (int i = 0; i < max_len; i++)
            {
                std::cout << s[i] << std::endl;
            }
        }
    private:
        enum { EMPTY = -1 };
        char* s;
        int max_len;
        int top;
};