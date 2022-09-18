#include "scientist.h"

#include <iostream>

void scientist::getdata()
{
    employee::getdata();
    std::cout << "\tEnter number of pubs: ";
    std::cin >> pubs;
}

void scientist::putdata()
{
    employee::putdata();
    std::cout << "\n\tNumber of publications: " << pubs << std::endl;
}

employee::employee_type scientist::get_type()
{
    return employee::employee_type::t_scientist;
}
