#include <iostream>
#include "./stack.h"

struct Pair
{
    int x, y;
};

class PairStack : public Stack2
{
protected:

    static const int MAX = 10;

public:
    void push(Pair p);
    Pair pop();
};

int main()
{
    return 0;
}

void PairStack::push(Pair p)
{
    Stack2::push(p.x);
    Stack2::push(p.y);
}

Pair PairStack::pop()
{
    Pair p; 

    p.y = Stack2::pop();
    p.x = Stack2::pop();

    return p;
}
