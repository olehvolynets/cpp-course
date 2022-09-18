#include <iostream>
#include <fstream>

#include "employee.h"
#include "laborer.h"
#include "manager.h"
#include "scientist.h"

class manager;
class scientist;
class laborer;

int employee::n = 0;
employee* employee::arrap[employee::MAXEM];

void employee::getdata()
{
    std::cin.ignore(10, '\n');
    std::cout << "\tEnter last name: ";
    std::cin >> name;
    std::cout << "\tEnter number: ";
    std::cin >> number;
}

void employee::putdata()
{
    std::cout << "\n\tName: " << name;
    std::cout << "\n\tNumber: " << number;
}

void employee::add()
{
    char ch;
    std::cout << "'m' - add a manager"
                 "\n's' - add a scientist"
                 "\n'l' - add a laborer"
                 "\nEnter selection: ";

    std::cin >> ch;

    switch (ch) {
    case 'm':
        arrap[n] = new manager;
        break;
    case 's':
        arrap[n] = new scientist;
        break;
    case 'l':
        arrap[n] = new laborer;
        break;
    default:
        std::cout << "\nUnknown employee type\n";
        return;
    }

    arrap[n++]->getdata();
}

void employee::display()
{
    for (int j = 0; j < n; j++) {
        std::cout << (j + 1);

        switch (arrap[j]->get_type()) {
        case t_manager:
            std::cout << ". Type: Manager";
            break;
        case t_scientist:
            std::cout << ". Type: Scientist";
            break;
        case t_laborer:
            std::cout << ". Type: Laborer";
            break;
        default:
            std::cout << ". Unknown type";
        }

        arrap[j]->putdata();
        std::cout << std::endl;
    }
}

void employee::write()
{
    int size;
    std::cout << "Writing " << n << " employees.\n";
    std::ofstream ouf;
    employee_type etype;
    ouf.open("EMPLOY.DAT", std::ios::trunc | std::ios::binary);
    if (!ouf) {
        std::cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < n; j++) // for every employee object
    {
        etype = arrap[j]->get_type();

        ouf.write((char*)&etype, sizeof(etype));
        switch (etype) // find its size
        {
        case t_manager:
            size = sizeof(manager);
            break;
        case t_scientist:
            size = sizeof(scientist);
            break;
        case t_laborer:
            size = sizeof(laborer);
            break;
        }
        ouf.write((char*)(arrap[j]), size);
        if (!ouf) {
            std::cout << "\nCan't write to file\n";
            return;
        }
    }
}

void employee::read()
{
    int size;
    employee_type etype;

    std::ifstream inf;

    inf.open("EMPLOY.DAT", std::ios::binary);
    if (!inf) {
        std::cout << "\nCan't open file\n";
        return;
    }

    n = 0;
    while (true) {
        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof())
            break;
        if (!inf) {
            std::cout << "\nCan't read type from file\n";
            return;
        }
        switch (etype) {
        case t_manager:
            arrap[n] = new manager;
            size = sizeof(manager);
            break;
        case t_scientist:
            arrap[n] = new scientist;
            size = sizeof(scientist);
            break;
        case t_laborer:
            arrap[n] = new laborer;
            size = sizeof(laborer);
            break;
        default:
            std::cout << "\nUnknown type in file\n";
            return;
        }
        inf.read((char*)arrap[n], size);
        if (!inf) {
            std::cout << "\nCan't read data from file\n";
            return;
        }
        n++;
    }

    std::cout << "Reading " << n << " employees" << std::endl;
}

void employee::find()
{
    std::cout << "Enter an employee number: ";
    unsigned long num = 0;
    std::cin >> num;

    for (int i = 0; i < n; ++i)
    {
        if (arrap[i]->number == num)
        {
            std::cout << "Found an employee with number " << num << " :\n";
            arrap[i]->putdata();
        }
    }
}
