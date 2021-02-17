#include <iostream>
class deque {
    public:
        void reset() { top = bottom = max_len / 2; top--; }
        void push_t(char c);
        void push_b(char c);
        char pop_t();
        char pop_b();
        void out_stack();
        char top_of();
        char bottom_of();
        bool empty();
        bool full();
    private:
        int adjust(int i);
        enum { max_len = 100 };
        char s[max_len];
        int bottom, top;
};