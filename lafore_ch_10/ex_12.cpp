#include <iostream>

int fmem_top = 0;
int pmem_top = 0;
float fmemory[4096 / sizeof(float)];
int pmemory[4096 / sizeof(int)];

class Float
{
public:
    int addr;

    Float(float f)
    {
        fmemory[fmem_top] = f;
        addr = fmem_top++;
    }

    int operator&()
    {
        return addr;
    }        
};

class ptrFloat
{
    int addr;

public:
    ptrFloat(int f_addr)
        : addr(f_addr)
    {
        pmemory[pmem_top++] = addr;
    }

    float& operator*()
    {
        return fmemory[pmemory[addr]];
    }
};

int main()
{
    Float var1 = 1.234;
    Float var2 = 5.678;

    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    std::cout << " *ptr1=" << *ptr1 << std::endl;
    std::cout << " *ptr2=" << *ptr2 << std::endl;

    *ptr1 = 7.123;
    *ptr2 = 8.456;

    std::cout << " *ptr1=" << *ptr1 << std::endl;
    std::cout << " *ptr2=" << *ptr2 << std::endl;

    return 0;
}
