#include <iostream>

double add(double a, double b, double c, double d);
double subtract(double a, double b, double c, double d);
double multiply(double a, double b, double c, double d);
double divide(double a, double b, double c, double d);

int main()
{
    using namespace std;

    double a, b, c, d;
    a = b = c = d = 0;
    char dummy;
    char operation;
    double divisible, divisor;

    while (true)
    {
        a = b = c = d = 0;
        divisible = divisor = 0;

        cout << "Enter an expression (a/b + c/d): ";
        cin >> a >> dummy >> b >> operation >> c >> dummy >> d;

        if (b == 0 || d == 0)
        {
            cout << "\nDivisor cant be 0." << endl;
            continue;
        }

        switch (operation) {
            case '+':
                divisible = (a * d + b * c);
                divisor = (b * d);
                break;
            case '-':
                divisible = (a * d + b * c);
                divisor = (b * d);
                break;
            case '*':
                divisible = (a * c);
                divisor = (b * d);
                break;
            case '/':
                divisible = (a * d);
                divisor = (b * c);
                break;
            default:
                cout << "Invalid operation..." << endl;
                break;
        }

        cout << "Resut: " << divisible << '/' << divisor << " (" << divisible / divisor << ')' << endl;

        cout << "Want to continue?(y/N): ";
        char next;
        cin >> next;
        if (next != 'y') {
            cout << int(next) << endl;
            break;
        }
    }

    return 0;
}
