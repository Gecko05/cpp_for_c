#include <iostream>
#include "ch_stack.h"

int main(int argc, char *argv[])
{
    char msg[40] = {"My name is Don Knuth!"};
    int i = 0;
    ch_stack s;

    std::cout << msg << std::endl;
    s.reset();
    while (msg[i] && !s.full())
    {
        s.push(msg[i++]);
    }
    s.reverse();
    while (!s.empty())
    {
        std::cout << s.pop();
    }
    
    std::cout << std::endl;
}