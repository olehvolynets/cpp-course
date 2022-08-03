#include <cstdlib>
#include <iostream>

class Frac
{
    double m_divisible, m_divisor;

public:

    Frac()
        : m_divisible(0), m_divisor(1)
    {}

    Frac(double divisibleValue, double divisorValue)
        : m_divisible(divisibleValue), m_divisor(divisorValue)
    {
        if (m_divisor == 0) throw;
    }

    inline double divisible() const { return m_divisible; }
    inline double divisor() const { return m_divisor; }

    void getFromInput()
    {
        char separator;

        std::cin >> m_divisible >> separator >> m_divisor;
    }

    void print()
    {
        std::cout << m_divisible << '/' << m_divisor << " (" << toDecimal() << ')';
    }

    Frac add(const Frac& other)
    {
        double newDivisible = (m_divisible * other.divisor() + m_divisor * other.divisible());
        double newDivisor = (m_divisor * other.divisor());

        return Frac(newDivisible, newDivisor);
    }

    Frac subtract(const Frac& other)
    {
        double newDivisible = (m_divisible * other.divisor() - m_divisor * other.divisible());
        double newDivisor = (m_divisor * other.divisor());

        return Frac(newDivisible, newDivisor);
    }

    Frac multiply(const Frac& other)
    {
        double newDivisible = m_divisible * other.divisible();
        double newDivisor = m_divisor * other.divisor();

        return Frac(newDivisible, newDivisor);
    }

    Frac divide(const Frac& other)
    {
        double newDivisible = m_divisible * other.divisor();
        double newDivisor = (m_divisor * other.divisible());

        return Frac(newDivisible, newDivisor);
    }

    double toDecimal() { return m_divisible / m_divisor; }
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
        f1.getFromInput();
        cin >> operation;
        f2.getFromInput();

        if (f1.divisor() == 0 || f2.divisor() == 0)
        {
            cout << "\nDivisor cant be 0." << endl;
            continue;
        }

        Frac result;

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

        cout << "Resut: "; 
        result.print();
        cout << endl;

        cout << "Want to continue?(y/N): ";
        char next;
        cin >> next;
        if (next != 'y') {
            break;
        }
    }

    return 0;
}
