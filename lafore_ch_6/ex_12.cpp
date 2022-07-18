#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

class Frac {
    int m_divisible, m_divisor;

    int m_gcd(int a, int b) const
    {  
        if (b == 0)
            return a;  
        else
            return m_gcd(b, a % b);
    }

public:
    static const int width = 8;

    Frac() : m_divisible(0), m_divisor(1) {}

    Frac(int divisibleValue, int divisorValue)
        : m_divisible(divisibleValue), m_divisor(divisorValue)
    {
        if (m_divisor == 0)
            throw;
    }

    inline int divisible() const { return m_divisible; }
    inline int divisor() const { return m_divisor; }

    void getFromInput() {
        char separator;

        std::cin >> m_divisible >> separator >> m_divisor;
    }

    std::string toString() const {
        int gcd = m_gcd(m_divisible, m_divisor);

        return std::to_string(m_divisible / gcd) + '/' + std::to_string(m_divisor / gcd);
    }

    Frac add(const Frac &other) const {
        int newDivisible =
            (m_divisible * other.divisor() + m_divisor * other.divisible());
        int newDivisor = (m_divisor * other.divisor());

        return Frac(newDivisible, newDivisor);
    }

    Frac subtract(const Frac &other) const {
        int newDivisible =
            (m_divisible * other.divisor() - m_divisor * other.divisible());
        int newDivisor = (m_divisor * other.divisor());

        return Frac(newDivisible, newDivisor);
    }

    Frac multiply(const Frac &other) const {
        int newDivisible = m_divisible * other.divisible();
        int newDivisor = m_divisor * other.divisor();

        return Frac(newDivisible, newDivisor);
    }

    Frac divide(const Frac &other) const {
        int newDivisible = m_divisible * other.divisor();
        int newDivisor = (m_divisor * other.divisible());

        return Frac(newDivisible, newDivisor);
    }

    int toDecimal() const { return m_divisible / m_divisor; }
};


int main() {
    using namespace std;

    int denominator;

    cout << "Denominator: ";
    cin >> denominator;
    cout << endl;

    for (int i = 1; i < denominator; ++i)
    {
        Frac f(i, denominator);

        cout << right << fixed;

        if (i == 1) {
            cout << setw(Frac::width * 2);
        } else {
            cout << setw(Frac::width);
        }

        cout << f.toString();
    }
    cout << endl;

    cout << setfill('-') << setw(Frac::width * denominator) << "-" << endl;
    cout << setfill(' ');

    for (int i = 1; i < denominator; ++i)
    {
        Frac f1(i, denominator);

        cout << setw(Frac::width) << f1.toString();

        for (int j = 1; j < denominator; ++j)
        {
            Frac f2(j, denominator);

            cout << setw(Frac::width) << f1.multiply(f2).toString();
        }

        cout << endl;
    }

    return 0;
}
