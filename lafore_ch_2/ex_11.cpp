#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printRow(string lastName, string firstName, string addr, string town, string state)
{
    cout << left << setw(15) << lastName
        << setw(15) << firstName
        << setw(20) << addr
        << setw(15) << town
        << setw(5) << state
        << endl;
}

int main()
{
    cout << left << setw(15) << "Last name"
        << setw(15) << "First name"
        << setw(20) << "Street address"
        << setw(15) << "Town"
        << setw(5) << "State" << endl;

    cout << setfill('-') << setw(15 + 15 + 20 + 15 + 5) << '-' << setfill(' ') << endl;

    printRow("Jones", "Bernard", "109 Pine Lane", "Littletown", "MI");
    printRow("O'Brian", "Coleen", "42 E. 99th Ave.", "Bigcity", "NY");
    printRow("Wong", "Harry", "121-A Alabama St.", "Lakeville", "IL");

    return 0;
}
