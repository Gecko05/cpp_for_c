#include "ch_stack.h"

int deque::adjust(int i)
{
    if (i < 0){
        i = max_len - 1;
    }
    else{
        i = i % max_len;
    }   
    return i;
}

void deque::push_t(char c)
{
    if (!full()){
        s[top++] = c;
        top = adjust(top);
    }
}

void deque::push_b(char c)
{
    if (!full()){
        s[bottom--] = c;
        bottom = adjust(bottom);
    }
}

char deque::pop_t()
{
    if (!empty())
    {
        top--;
        top = adjust(top);
        return s[top];
    }
    exit(1);
}

char deque::pop_b()
{
    if (!empty())
    {
        bottom++;
        bottom = adjust(bottom);
        return s[bottom];
    }
    exit(1);
}

void deque::out_stack()
{
    for (int i = bottom; i != top; i = adjust(i+1))
    {
        std::cout << s[i];
    }
}

char deque::top_of()
{
    return s[top];
}

char deque::bottom_of()
{
    return s[bottom];
}

bool deque::empty()
{
    return top == bottom;
}

bool deque::full()
{
    int c = bottom;
    c = adjust(c + 1);
    if (c == top){
        return true;
    }
    return false;
}