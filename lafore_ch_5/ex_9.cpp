#include <iostream>

void Print()
{
    static int count = 0;

    ++count;

    std::cout << "Has been called " << count << " times" << std::endl;
}
int main()
{
    for (int i = 0; i < 10; ++i)
        Print();

    return 0;
}
