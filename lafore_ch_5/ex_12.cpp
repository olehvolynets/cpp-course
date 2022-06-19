#include <iostream>

struct Frac
{
    double divisible, divisor;

    Frac()
        : divisible(0), divisor(1)
    {}

    Frac(double divisibleValue, double divisorValue)
        : divisible(divisibleValue), divisor(divisorValue)
    {
        if (divisor == 0) throw;
    }

    Frac* add(const Frac& other)
    {
        double newDivisible = (divisible * other.divisor + divisor * other.divisible);
        double newDivisor = (divisor * other.divisor);

        return new Frac(newDivisible, newDivisor);
    }

    Frac* subtract(const Frac& other)
    {
        double newDivisible = (divisible * other.divisor - divisor * other.divisible);
        double newDivisor = (divisor * other.divisor);

        return new Frac(newDivisible, newDivisor);
    }

    Frac* multiply(const Frac& other)
    {
        double newDivisible = divisible * other.divisible;
        double newDivisor = divisor * other.divisor;

        return new Frac(newDivisible, newDivisor);
    }

    Frac* divide(const Frac& other)
    {
        double newDivisible = divisible * other.divisor;
        double newDivisor = (divisor * other.divisible);

        return new Frac(newDivisible, newDivisor);
    }

    double toDecimal() { return divisible / divisor; }
};

int main()
{
    using namespace std;

    char separator;
    char operation;

    while (true)
    {
        Frac f1, f2;

        cout << "Enter an expression (a/b + c/d): ";
        cin >> f1.divisible >> separator >> f1.divisor
            >> operation
            >> f2.divisible >> separator >> f2.divisor;

        if (f1.divisor == 0 || f2.divisor == 0)
        {
            cout << "\nDivisor cant be 0." << endl;
            continue;
        }

        Frac* result;

        switch (operation) {
            case '+':
                result = f1.add(f2);
                break;
            case '-':
                result = f1.subtract(f2);
                break;
            case '*':
                result = f1.multiply(f2);
                break;
            case '/':
                result = f1.divide(f2);
                break;
            default:
                cout << "Invalid operation..." << endl;
                break;
        }

        cout << "Resut: " << result->divisible << '/' << result->divisor
            << " (" << result->toDecimal() << ')' << endl;

        delete result;

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
