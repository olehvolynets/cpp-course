#include <iostream>

class sterling
{
    long pounds;
    int shillings, pence;

    void setFromDouble(double dPounds);

    double convertShillings(int s) { return (1.0L / 20) * s; }
    double convertPence(int p) { return (1.0L / (20 * 12)) * p; }

public:
    sterling()
      : pounds(0), shillings(0), pence(0)
    {}

    sterling(double dPounds)
    {
        setFromDouble(dPounds);
    }

    sterling(long a_pounds, int a_shillings, int a_pence)
        : pounds(a_pounds), shillings(a_shillings), pence(a_pence)
    {}

    void getSterling();
    void putSterling() const;

    sterling operator+(sterling other) const;
    sterling operator-(sterling other) const;
    sterling operator*(sterling other) const;
    sterling operator/(sterling other) const;
    sterling operator/(double dOther) const;

    operator double() const;
};

void sterling::setFromDouble(double dPounds)
{
    pounds = static_cast<int>(dPounds);
    double rest = dPounds - pounds;

    shillings = rest / 0.05f;
    rest -= convertShillings(shillings);

    pence = rest / (1.0L / 240);
}

void sterling::getSterling()
{
    double dPounds = 0;
    std::cout << "Enter decimal punds: ";
    std::cin >> dPounds;

    setFromDouble(dPounds);
}

void sterling::putSterling() const
{
    std::cout << "£" << pounds << '.' << shillings << '.' << pence << std::endl;
}

sterling::operator double() const
{
    int decimal = pence + (shillings * 12);

    return pounds + (static_cast<double>(decimal) / 240.0L);
}

sterling sterling::operator+(sterling other) const
{
    return sterling(double(*this) + double(other));
}

sterling sterling::operator-(sterling other) const
{
    return sterling(double(*this) - double(other));
}

sterling sterling::operator*(sterling other) const
{
    return sterling(double(*this) * double(other));
}

sterling sterling::operator/(sterling other) const
{
    return sterling(double(*this) / double(other));
}

sterling sterling::operator/(double dOther) const
{
    return sterling(double(*this) / dOther);
}
