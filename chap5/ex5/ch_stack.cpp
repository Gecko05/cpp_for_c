#include "ch_stack.h"
#include <cstring>

ch_stack::ch_stack(const char* c)
{
    int len = strlen(c);
    assert(len > 0);
    max_len = len;
    top = EMPTY;
    s = new char[max_len];
    assert(s != 0);
    memcpy(s, c, max_len);
}