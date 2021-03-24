#include <iostream>
#include "ch_stack.h"

int main(int argc, char *argv[])
{
    ch_stack stack1(10);
    ch_stack stack2(10);
    ch_stack stack3(10);
    ch_stack stack4(10);

    for (int i = 0; i < 10; i++)
    {
        stack1.push(i + 48);
        stack2.push((9-i) + 48);
    }
    stack1.print();
    stack2.print();
    for (int i = 0; i < 10; i++){
        stack3.push(stack1.pop());
        stack4.push(stack2.pop());
    }

    for (int i = 0; i < 10; i++){
        stack2.push(stack3.pop());
        stack1.push(stack4.pop());
    }

    std::cout << std::endl;
    stack1.print();
    stack2.print();
}