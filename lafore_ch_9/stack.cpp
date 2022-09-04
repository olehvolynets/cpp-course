#include "./stack.h"
#include <iostream>

void Stack::push(int var)
{
    st[++top] = var;
}

int Stack::pop()
{
    return st[top--];
}

void Stack2::push(int var)
{
    if (top >= MAX-1)
    {
        std::cout << "\nError: stack is full\n";
        exit(1);

        Stack::push(var);
    }
}

int Stack2::pop()
{
    if (top < 0)
    {
        std::cout << "\nError: stack is empty\n";
        exit(1);
    }

    return Stack::pop();
}
