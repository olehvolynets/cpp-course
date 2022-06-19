#include <iostream>

struct Time
{
    int hours, minutes, seconds;
};

int main()
{
    Time t;
    char sep;

    std::cout << "Enter current time (fmt HH:MM:SS): ";
    std::cin >> t.hours >> sep >> t.minutes >> sep >> t.seconds;
    std::cout << std::endl;

    long totalsecs = t.hours * 3600 + t.minutes * 60 + t.seconds;

    std::cout << "Total sec: " << totalsecs << std::endl;

    return 0;
}
