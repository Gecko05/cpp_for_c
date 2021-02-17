#include "ch_stack.h"

void ch_stack::reverse()
{
    char st[max_len];
    int i = 0;
    int ln = this->top;
    while(!this->empty())
    {
        st[i++] = this->pop();
    }
    for (int j = 0; j < i; j++)
    {
        this->s[j] = st[j];
    }
    this->top = ln;
}

void ch_stack::pushm(int n, const char s1[])
{
    for (int i = 0; i < n; i++)
    {
        if (!ch_stack::full())
        {
            ch_stack::push(s1[i]);
        }
    }
}

void ch_stack::popm(int n, char s1[])
{
    for (int i = 0; i < n; i++)
    {
        if (!ch_stack::empty())
        {
            s1[i] = ch_stack::pop();
        }
    }
}