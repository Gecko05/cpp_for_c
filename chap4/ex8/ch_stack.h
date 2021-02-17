#include <iostream>
class ch_stack {
    public:
        void reset() { top = EMPTY; }
        void push(char c) { if (full()){std::cerr << "Unable"; exit(1);}; top++; s[top] = c; }
        char pop() { if (empty()){std::cerr << "Unable"; exit(1);}; return s[top--]; }
        char top_of() const { return s[top]; }
        bool empty() const { return (top == EMPTY); }
        bool full() const { return (top == FULL); }
        void pushm(int n, const char s1[]);
        void popm(int n, char s1[]);
        void reverse();
    private:
        enum { max_len = 100, EMPTY = -1, FULL = max_len-1 };
        char s[max_len];
        int top;
};