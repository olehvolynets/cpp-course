#include <iostream>
#include <string>

using namespace std;

/*
One of the weaknesses of C++ for writing business programs is that it does not
contain a built-in type for monetary values such as $173,698,001.32. Such a
money type should be able to store a number with a fixed decimal point and about
17 digits of precision, which is enough to handle the national debt in dollars
and cents. Fortunately, the built-in C++ type long double has 19 digits of
precision, so we can use it as the basis of a money class, even though it uses a
floating decimal. However, we'll need to add the capability to input and output
money amounts preceded by a dollar sign and divided by commas into groups of
three digits; this makes it much easier to read large numbers. As a first step
toward developing such a class, write a function called mstold () that takes a
money string, a string representing a money amount like
"$1,234,567,890, 123.99'
as an argument, and returns the equivalent long double.
You'll need to treat the money string as an array of characters, and go through
it character by character, copying only digits (1-9) and the decimal point into
another string. Ignore everything else, including the dollar sign and the
commas. You can then use the atold () library function (note the initial
underscore- header file STDLIB.H or MATH.H) to convert the resulting pure string
to a long double. Assume that money values will never be negative. Write a
main() program to test mstold () by repeatedly obtaining a money string from the
user and displaying the corresponding long double.
*/

long double mstold(const string& amountString);

int main()
{
    while (true)
    {
        string amountString;

        cout << "Enter amount: ";
        cin >> amountString;
        cout << endl;

        long double amount = mstold(amountString);

        cout << "Double: " << fixed << amount << endl;
    }

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
