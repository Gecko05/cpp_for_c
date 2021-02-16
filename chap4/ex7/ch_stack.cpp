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