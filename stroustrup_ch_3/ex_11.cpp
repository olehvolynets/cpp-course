#include <iostream>

class Wallet
{
public:
    int pennies;
    int nickels;
    int dimes;
    int quarters;
    int halves;
    int dollars;

    Wallet()
        : pennies(0), nickels(0), dimes(0),
        quarters(0), halves(0), dollars(0)
    {}

    void prompt()
    {
        std::cout << "How many pennies do you have? ";
        std::cin >> pennies;

        std::cout << "How many nickels do you have? ";
        std::cin >> nickels;

        std::cout << "How many dimes do you have? ";
        std::cin >> dimes;

        std::cout << "How many quarters do you have? ";
        std::cin >> quarters;

        std::cout << "How many halves do you have? ";
        std::cin >> halves;

        std::cout << "How many dollars do you have? ";
        std::cin >> dollars;
    }

    int sum()
    {
        return pennies + (nickels * 5) + (dimes * 10) + (quarters * 25) + (halves * 50) + (dollars * 100);
    }

    void pretty_print()
    {
        int total_cents = sum();
        int dollars = total_cents / 100;
        float cents = total_cents % 100;
        std::cout << '$' << dollars << '.' << cents;
    }
};

int main()
{
    Wallet w;

    w.prompt();

    std::cout << "The total value of your wallet is ";
    w.pretty_print();
    std::cout << std::endl;

    return 0;
}
