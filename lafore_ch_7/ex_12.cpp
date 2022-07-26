#include <iostream>
#include <string>

using namespace std;

/*
Create a class called bMoney. It should store money amounts as long doubles. Use
the unction mstold () to convert a money string entered as input into a long
double, and the function 1dtoms () to convert the long double to a money string
for display. (See Exercises 6 and 10.) You can call the input and output member
functions getmoney () and putmoney (). Write another member function that adds
two bMoney amounts; you can call it madd(). Adding Money objects is easy: Just
add the long double member data amounts in two Money objects. Write a main()
program that repeatedly asks the user to enter two money strings, and then
displays the sum as a money string.
*/

long double mstold(const string& amountString);
string ldtoms(long double amount);

class bMoney
{
    long double m_money;

public:
    bMoney()
        : m_money(0)
    {}

    bMoney(string s)
    {
        m_money = mstold(s);
    }

    void madd(bMoney m1, bMoney m2)
    {
        m_money = m1.m_money + m2.m_money;
    }

    void getMoney()
    {
        string input;

        cout << "Enter money: ";
        cin >> input;
        cout << endl;

        m_money = mstold(input);
    }

    void putMoney()
    {
        cout << ldtoms(m_money) << endl;
    }
};

int main()
{
    bMoney m;

    m.getMoney();

    m.putMoney();

    return 0;
}

long double mstold(const string& amountString)
{
    string numberString;
    numberString.reserve(amountString.size());

    for (int i = 0; i < amountString.size(); ++i)
    {
        char current = amountString.at(i);

        if (current != '.' && !(current >= '0' && current <= '9'))
            continue;

        numberString.push_back(current);
    }

    return stold(numberString);
}

string ldtoms(long double amount)
{
    string s = to_string(amount);

    int i = s.size() - 1;

    char current;

    while ((current = s.at(i--)) != '.');

    for (int counter = 1; i >= 0; --i, ++counter)
    {
       if (counter == 3 && i != 0)
       {
           s.insert(i, ",");
           counter = 0;
       }
    }

    s.insert(0, "$");

    return s;
}
