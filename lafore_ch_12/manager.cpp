#include "manager.h"

#include <iostream>

void manager::getdata()
{
    employee::getdata();
    std::cout << "\tEnter title: ";
    std::cin >> title;
    std::cout << "\tEnter golf club dues: ";
    std::cin >> dues;
}

void manager::putdata()
{
    employee::putdata();
    std::cout << "\tTitle: " << title;
    std::cout << "\n\tGolf club dues: " << dues;
}

employee::employee_type manager::get_type()
{
    return employee::employee_type::t_manager;
}
