#include <fstream>
#include <iostream>
#include <typeinfo>

#include "manager.h"
#include "scientist.h"
#include "laborer.h"

int main()
{
    char ch;
    while (true)
    {
        std::cout << "'a' -- add data for an employee"
                     "\n'd' -- display data for all employees"
                     "\n'f' - find an employee"
                     "\n'r' -- read all employee data from file"
                     "\n'w' -- write all employee data to file"
                     "\n'x' -- exit"
                     "\nEnter selection: ";

        std::cin >> ch;

        switch (ch)
        {
        case 'a':
            employee::add();
            break;
        case 'd':
            employee::display();
            break;
        case 'r':
            employee::read();
            break;
        case 'w':
            employee::write();
            break;
        case 'f':
            employee::find();
            break;
        case 'x':
            exit(0);
        default:
            std::cout << "\nUnknown command";
        }
    }
    return 0;
}
