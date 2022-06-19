#include <iostream>

#define LOG(x) std::cout << x << std::endl

struct Time
{
    int hours, minutes, seconds;

    Time()
        : hours(0), minutes(0), seconds(0)
    {
    }

    Time(long sec)
    {
        hours = sec / 3600;
        sec -= hours * 3600;
        minutes = sec / 60;
        sec -= minutes * 60;
        seconds = sec;
    }

    void prompt(int n)
    {
        char sep;

        std::cout << "Enter time " << n << "(fmt HH:MM:SS): ";
        std::cin >> hours >> sep >> minutes >> sep >> seconds;
    }

    long totalsec()
    {
        return hours * 3600 + minutes * 60 + seconds;
    }
};

int main()
{
    Time t1, t2;

    t1.prompt(1);
    t2.prompt(2);

    Time t3(t1.totalsec() + t2.totalsec());

    std::cout << t3.hours << ":" << t3.minutes << ":" << t3.seconds << std::endl;

    return 0;
}
